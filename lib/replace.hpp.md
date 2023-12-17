---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/sample.test.cpp
    title: verify/sample.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/replace.hpp\"\n\n\n#include <functional>\n#include <type_traits>\n\
    #include <algorithm>\n#include <ranges>\n#include <concepts>\n\n\nnamespace library\
    \ {\n\n\ntemplate<\n    std::ranges::range Res,\n    std::ranges::range Source,\
    \ std::ranges::range From, std::ranges::range To,\n    class Pred = std::ranges::equal_to,\n\
    \    class SProj = std::identity, class FProj = std::identity, class TProj = std::identity\n\
    >\n    requires\n        std::default_initializable<std::remove_reference_t<Res>>\
    \ &&\n        requires (\n            Res res, std::ranges::sentinel_t<Res> sent,\n\
    \            std::ranges::iterator_t<To> t_iter, std::ranges::sentinel_t<To> t_sent\n\
    \        ) {\n            res.insert(sent, t_iter, t_sent);\n        }\nconstexpr\
    \ auto replace(\n    Source&& source, From&& from, To&& to,\n    Pred = {},\n\
    \    SProj = {}, FProj = {}, TProj = {},\n    std::nullptr_t = {}\n) {\n\n   \
    \ const auto f_len = std::ranges::distance(from);\n\n    std::remove_reference_t<Res>\
    \ res;\n    {\n        auto itr = std::ranges::begin(source);\n        auto s_end\
    \ = std::ranges::end(source);\n\n        auto f_begin = std::ranges::begin(from);\n\
    \        auto f_end = std::ranges::end(from);\n\n        auto t_begin = std::ranges::begin(to);\n\
    \        auto t_end = std::ranges::end(to);\n\n        for(; itr != s_end; ) {\n\
    \            auto next = std::ranges::next(itr, f_len, s_end);\n            const\
    \ bool hit = std::ranges::equal(\n                itr, next,\n               \
    \ f_begin, f_end,\n                Pred{}, SProj{}, FProj{}\n            );\n\n\
    \            if(hit) {\n                std::ranges::transform(t_begin, t_end,\
    \ std::back_inserter(res), std::identity{}, TProj{});\n                itr = next;\n\
    \            }\n            else {\n                res.insert(std::ranges::end(res),\
    \ *itr);\n                ++itr;\n            }\n\n        }\n    }\n\n    return\
    \ res;\n}\n\n\ntemplate<\n    std::ranges::range Source, std::ranges::range From,\
    \ std::ranges::range To,\n    class Pred = std::ranges::equal_to,\n    class SProj\
    \ = std::identity, class FProj = std::identity, class TProj = std::identity\n\
    >\nconstexpr auto replace(Source&& source, From&& from, To&& to, Pred = {}, SProj\
    \ = {}, FProj = {}, TProj = {}) {\n    return replace<Source>(source, from, to,\
    \ Pred{}, SProj{}, FProj{}, TProj{}, nullptr);\n}\n\n\n} // namespace library\n"
  code: "#pragma once\n\n\n#include <functional>\n#include <type_traits>\n#include\
    \ <algorithm>\n#include <ranges>\n#include <concepts>\n\n\nnamespace library {\n\
    \n\ntemplate<\n    std::ranges::range Res,\n    std::ranges::range Source, std::ranges::range\
    \ From, std::ranges::range To,\n    class Pred = std::ranges::equal_to,\n    class\
    \ SProj = std::identity, class FProj = std::identity, class TProj = std::identity\n\
    >\n    requires\n        std::default_initializable<std::remove_reference_t<Res>>\
    \ &&\n        requires (\n            Res res, std::ranges::sentinel_t<Res> sent,\n\
    \            std::ranges::iterator_t<To> t_iter, std::ranges::sentinel_t<To> t_sent\n\
    \        ) {\n            res.insert(sent, t_iter, t_sent);\n        }\nconstexpr\
    \ auto replace(\n    Source&& source, From&& from, To&& to,\n    Pred = {},\n\
    \    SProj = {}, FProj = {}, TProj = {},\n    std::nullptr_t = {}\n) {\n\n   \
    \ const auto f_len = std::ranges::distance(from);\n\n    std::remove_reference_t<Res>\
    \ res;\n    {\n        auto itr = std::ranges::begin(source);\n        auto s_end\
    \ = std::ranges::end(source);\n\n        auto f_begin = std::ranges::begin(from);\n\
    \        auto f_end = std::ranges::end(from);\n\n        auto t_begin = std::ranges::begin(to);\n\
    \        auto t_end = std::ranges::end(to);\n\n        for(; itr != s_end; ) {\n\
    \            auto next = std::ranges::next(itr, f_len, s_end);\n            const\
    \ bool hit = std::ranges::equal(\n                itr, next,\n               \
    \ f_begin, f_end,\n                Pred{}, SProj{}, FProj{}\n            );\n\n\
    \            if(hit) {\n                std::ranges::transform(t_begin, t_end,\
    \ std::back_inserter(res), std::identity{}, TProj{});\n                itr = next;\n\
    \            }\n            else {\n                res.insert(std::ranges::end(res),\
    \ *itr);\n                ++itr;\n            }\n\n        }\n    }\n\n    return\
    \ res;\n}\n\n\ntemplate<\n    std::ranges::range Source, std::ranges::range From,\
    \ std::ranges::range To,\n    class Pred = std::ranges::equal_to,\n    class SProj\
    \ = std::identity, class FProj = std::identity, class TProj = std::identity\n\
    >\nconstexpr auto replace(Source&& source, From&& from, To&& to, Pred = {}, SProj\
    \ = {}, FProj = {}, TProj = {}) {\n    return replace<Source>(source, from, to,\
    \ Pred{}, SProj{}, FProj{}, TProj{}, nullptr);\n}\n\n\n} // namespace library\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/replace.hpp
  requiredBy: []
  timestamp: '2023-12-17 18:24:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/sample.test.cpp
documentation_of: lib/replace.hpp
layout: document
redirect_from:
- /library/lib/replace.hpp
- /library/lib/replace.hpp.html
title: lib/replace.hpp
---
