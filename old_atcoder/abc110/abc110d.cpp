// https://beta.atcoder.jp/contests/abc110

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

const int MOD = 1000000007;
const int MAX_N = 2 * 100000 + 10;
ui64 f[MAX_N];
ui64 f_inv[MAX_N];

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i != 0) continue;
        int n = 0;
        while (x % i == 0) { n++; x /= i; }
        factors.emplace_back(i, n);
    }
    if (x != 1) factors.emplace_back(x, 1);
    return move(factors);
}

ui64 power(ui64 x, ui64 n, ui64 mod) {
    ui64 res = 1;
    while (n != 0) {
        if (n % 2 == 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ui64 inverse_element(ui64 x, ui64 mod) { return power(x, mod - 2, mod); }

template <std::size_t Size>
void init_factorial(ui64 f[Size], ui64 f_inv[Size], ui64 mod) {
    f[0] = f[1] = 1;
    f_inv[0] = f_inv[1] = 1;
    for (ui64 i = 2; i < Size; ++i) f[i] = i * f[i - 1] % mod;
    for (ui64 i = 2; i < Size; ++i) f_inv[i] = inverse_element(f[i], mod) % mod;
}

// nCk
ui64 nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return f[n] % MOD * f_inv[n - k] % MOD * f_inv[k] % MOD;
}


int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(100000 1000000000
)");
#endif
    init_factorial<MAX_N>(f, f_inv, MOD);

    int N, M;
    in >> N >> M;

    auto factors = factorize(M);
    ui64 ans = 1;
    for (auto factor : factors) ans = ans * nCk(factor.second + N - 1, N - 1) % MOD;
    cout << ans << endl;
    return 0;
}