// https://beta.atcoder.jp/contests/abc070

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
T gcd(T x, T y) {
    if (x < y) swap(x, y);
    while (0 < y) {
        auto r = x % y;
        x = y, y = r;
    }

    return x;
}

int main() {
    int n;
    cin >> n;
    uint64_t ans;
    for (int i = 0; i < n; ++i) {
        uint64_t t;
        cin >> t;

        if (i == 0) ans = t;
        else ans *= t / gcd(ans, t);
    }
    cout << ans << endl;
    return 0;
}