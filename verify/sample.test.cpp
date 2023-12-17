/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ 20 GCC */

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"


#include <iostream>
#include <cassert>

#include <atcoder/modint>

#include "../lib/replace.hpp"


signed main() {
    std::cout << "Hello World\n";

    {
        using namespace std::literals::string_literals;

        std::string message = "A of X, by X, for X.";

        message = library::replace(message, "A"s, "Life"s);
        message = library::replace(message, "X"s, "Twitter"s);

        assert(message == "Life of Twitter, by Twitter, for Twitter.");
    }

    {
        assert(atcoder::modint998244353{ 2 }.inv() == (998244353 + 1) / 2);
    }
}
