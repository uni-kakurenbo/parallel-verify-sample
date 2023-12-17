#pragma once


#include <functional>
#include <type_traits>
#include <algorithm>
#include <ranges>
#include <concepts>


namespace library {


template<
    std::ranges::range Res,
    std::ranges::range Source, std::ranges::range From, std::ranges::range To,
    class Pred = std::ranges::equal_to,
    class SProj = std::identity, class FProj = std::identity, class TProj = std::identity
>
    requires
        std::default_initializable<std::remove_reference_t<Res>> &&
        requires (
            Res res, std::ranges::sentinel_t<Res> sent,
            std::ranges::iterator_t<To> t_iter, std::ranges::sentinel_t<To> t_sent
        ) {
            res.insert(sent, t_iter, t_sent);
        }
constexpr auto replace(
    Source&& source, From&& from, To&& to,
    Pred = {},
    SProj = {}, FProj = {}, TProj = {},
    std::nullptr_t = {}
) {

    const auto f_len = std::ranges::distance(from);

    std::remove_reference_t<Res> res;
    {
        auto itr = std::ranges::begin(source);
        auto s_end = std::ranges::end(source);

        auto f_begin = std::ranges::begin(from);
        auto f_end = std::ranges::end(from);

        auto t_begin = std::ranges::begin(to);
        auto t_end = std::ranges::end(to);

        for(; itr != s_end; ) {
            auto next = std::ranges::next(itr, f_len, s_end);
            const bool hit = std::ranges::equal(
                itr, next,
                f_begin, f_end,
                Pred{}, SProj{}, FProj{}
            );

            if(hit) {
                std::ranges::transform(t_begin, t_end, std::back_inserter(res), std::identity{}, TProj{});
                itr = next;
            }
            else {
                res.insert(std::ranges::end(res), *itr);
                ++itr;
            }

        }
    }

    return res;
}


template<
    std::ranges::range Source, std::ranges::range From, std::ranges::range To,
    class Pred = std::ranges::equal_to,
    class SProj = std::identity, class FProj = std::identity, class TProj = std::identity
>
constexpr auto replace(Source&& source, From&& from, To&& to, Pred = {}, SProj = {}, FProj = {}, TProj = {}) {
    return replace<Source>(source, from, to, Pred{}, SProj{}, FProj{}, TProj{}, nullptr);
}


} // namespace library
