// https://beta.atcoder.jp/contests/ddcc2019-qual

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

using ui64 = unsigned long long;
using i64 = long long;
const ui64 MOD = 1000000007;

// 二分累乗法
// x^n % mod
ui64 power(ui64 x, ui64 n, ui64 mod) {
    ui64 res = 1;
    while (n != 0) {
        if (n % 2 == 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ui64 n;
    cin >> n;

    ui64 ans = 0;
    for (ui64 p_max = 1; p_max <= n; ++p_max) {
        ui64 p_ways = power(p_max, 10, MOD) - power(p_max - 1, 10, MOD) + MOD;
        ui64 q_ways = power(n / p_max, 10, MOD);
        ans = (ans + p_ways * q_ways) % MOD;
    }
    cout << ans << endl;
    return 0;
}