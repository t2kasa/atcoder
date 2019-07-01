#include <bits/stdc++.h>

using namespace std;

vector<int64_t> factorize(int64_t x) {
    vector<int64_t> prime_factors;

    int64_t factor = 2;
    while (x != 1) {
        if (x % factor == 0) {
            prime_factors.emplace_back(factor);
            x /= factor;
        } else {
            factor++;
        }
    }

    return prime_factors;
}

template <typename T>
size_t count_n_digits(T x) {
    string str = to_string(x);
    return str.length();
}
