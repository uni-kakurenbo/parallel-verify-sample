---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/replace.hpp
    title: lib/replace.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://creativecommons.org/publicdomain/zero/1.0/deed.ja
    - https://github.com/uni-kakurenbo/competitive-programming-workspace
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"verify/sample.test.cpp\"\n/*\n * @uni_kakurenbo\n * https://github.com/uni-kakurenbo/competitive-programming-workspace\n\
    \ *\n * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja\n */\n\
    /* #language C++ 20 GCC */\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n\n#include <iostream>\n#include <cassert>\n\n#include <atcoder/modint>\n\n\
    #line 2 \"lib/replace.hpp\"\n\n\n#include <functional>\n#include <type_traits>\n\
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
    \ Pred{}, SProj{}, FProj{}, TProj{}, nullptr);\n}\n\n\n} // namespace library\n\
    #line 18 \"verify/sample.test.cpp\"\n\n\nsigned main() {\n    std::cout << \"\
    Hello World\\n\";\n\n    {\n        using namespace std::literals::string_literals;\n\
    \n        std::string message = \"A of X, by X, for X.\";\n\n        message =\
    \ library::replace(message, \"A\"s, \"Life\"s);\n        message = library::replace(message,\
    \ \"X\"s, \"Twitter\"s);\n\n        assert(message == \"Life of Twitter, by Twitter,\
    \ for Twitter.\");\n    }\n\n    {\n        assert(atcoder::modint998244353{ 2\
    \ }.inv() == (998244353 + 1) / 2);\n    }\n}\n"
  code: "/*\n * @uni_kakurenbo\n * https://github.com/uni-kakurenbo/competitive-programming-workspace\n\
    \ *\n * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja\n */\n\
    /* #language C++ 20 GCC */\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n\n#include <iostream>\n#include <cassert>\n\n#include <atcoder/modint>\n\n\
    #include \"../lib/replace.hpp\"\n\n\nsigned main() {\n    std::cout << \"Hello\
    \ World\\n\";\n\n    {\n        using namespace std::literals::string_literals;\n\
    \n        std::string message = \"A of X, by X, for X.\";\n\n        message =\
    \ library::replace(message, \"A\"s, \"Life\"s);\n        message = library::replace(message,\
    \ \"X\"s, \"Twitter\"s);\n\n        assert(message == \"Life of Twitter, by Twitter,\
    \ for Twitter.\");\n    }\n\n    {\n        assert(atcoder::modint998244353{ 2\
    \ }.inv() == (998244353 + 1) / 2);\n    }\n}\n"
  dependsOn:
  - lib/replace.hpp
  isVerificationFile: true
  path: verify/sample.test.cpp
  requiredBy: []
  timestamp: '2023-12-17 18:24:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sample.test.cpp
layout: document
redirect_from:
- /verify/verify/sample.test.cpp
- /verify/verify/sample.test.cpp.html
title: verify/sample.test.cpp
---
