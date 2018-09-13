// https://beta.atcoder.jp/contests/abc065

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

const ui64 MOD =  1000000007;
// 階乗と階乗の逆元 mod
const ui64 SIZE = 100001;
ui64 f[SIZE];
ui64 f_inv[SIZE];

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

// 逆元
ui64 inverse_element(ui64 x, ui64 mod) {
    return power(x, mod - 2, mod);
}

void init() {
    auto size = SIZE;
    f[0] = f[1] = 1;
    for (ui64 i = 2; i < size; ++i) f[i] = i * f[i - 1] % MOD;

    f_inv[0] = f_inv[1] = 1;
    for (ui64 i = 2; i < size; ++i) f_inv[i] = inverse_element(f[i], MOD) % MOD;
}

int main() {
    init();

    int n, m;
    cin >> n >> m;
    if (1 < abs(n - m)) {
        cout << "0" << endl;
        exit(0);
    }

    if (abs(n - m) == 1) {
        ui64 ans = f[n] * f[m] % MOD;
        cout << ans  << endl;
        exit(0);
    }

    if (abs(n - m) == 0) {
        ui64 ans = f[n] * f[m] % MOD * 2 % MOD;
        cout << ans  << endl;
        exit(0);
    }

    return 0;
}