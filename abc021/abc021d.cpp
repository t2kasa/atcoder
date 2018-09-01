// https://beta.atcoder.jp/contests/abc021
// status: [review][solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using ui64 = uint64_t;
using namespace std;

const ui64 MOD =  1000000007;
const int MAX_N = 100000;
const int MAX_K = 100000;

// 階乗と階乗の逆元 mod
ui64 f[(MAX_N + MAX_K - 1) + 1];
ui64 f_inv[(MAX_N + MAX_K - 1) + 1];

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
    auto size = (MAX_N + MAX_K - 1) + 1;
    f[0] = f[1] = 1;
    for (ui64 i = 2; i < size; ++i) f[i] = i * f[i - 1] % MOD;

    f_inv[0] = f_inv[1] = 1;
    for (ui64 i = 2; i < size; ++i) f_inv[i] = inverse_element(f[i], MOD) % MOD;
}

ui64 solve(ui64 n, ui64 k) {
    // nHk = n+k-1Cn-1 = (n + k - 1)! / (k! * (n - 1)!)
    return f[n + k - 1] * f_inv[k] % MOD * f_inv[n - 1] % MOD;
}

/*
// dp[i][j] i種類の品物を重複ありでj個選ぶ組み合わせの総数
// nC0 = 1
// 重複組合せではnHk = n+k-1Ck
// nCk = n-1Cr-1 + n-1Crの公式を用いる
// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][r];
ui32 dp[(MAX_N + MAX_K - 1) + 1][MAX_K + 1];

ui32 solve(int n, int k, ui32 mod) {
    for (int i = 0; i < MAX_N + 1; ++i) dp[i][0] = 1;

    for (int i = 0; i < n + k - 1; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] + dp[i][j]) % mod;
        }
    }

    return dp[n + k - 1][k];
}
*/

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto input = std::string(R"(400
296
)");
    stringstream stream(input);
#endif
    ui64 n, k;
    stream >> n >> k;

    init();
    auto ans = solve(n, k);
    cout << ans << endl;
    return 0;
}