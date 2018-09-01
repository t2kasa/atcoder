// https://beta.atcoder.jp/contests/tdpc
// status: [review][solve]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const ui64 MOD = 1000000007;
const ui64 MAX_N = 26;
const ui64 MAX_FREQ = 10;

// dp[i][j] i種類までの文字を用いたときに同じ文字が隣り合っている箇所がj個ある組み合わせの総数
// ans: dp[n][0] n種類までの文字を用いて同じ文字が隣り合っている箇所が0個
ui64 dp[30][500];

// 階乗と逆元
ui64 f[500];
ui64 f_inv[500];

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
ui64 inverse_element(ui64 x, ui64 mod) { return power(x, mod - 2, mod); }

template <std::size_t Size>
void init_factorial(ui64 f[Size], ui64 f_inv[Size], ui64 mod) {
    f[0] = f[1] = 1;
    f_inv[0] = f_inv[1] = 1;
    for (ui64 i = 2; i < Size; ++i) f[i] = i * f[i - 1] % mod;
    for (ui64 i = 2; i < Size; ++i) f_inv[i] = inverse_element(f[i], mod) % mod;
}

// nCk
ui64 comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return f[n] % MOD * f_inv[n - k] % MOD * f_inv[k] % MOD;
}

ui64 solve(const vector<int>& freq) {
    auto n = freq.size();
    init_factorial<sizeof(f) / sizeof(std::size_t)>(f, f_inv, MOD);

    int len = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len + 1; ++j) {
            if (dp[i][j] == 0) continue;

            for (int k = 1; k <= freq[i]; ++k) {
                for (int l = 0; l <= min(j, k); ++l) {
                    int u = j - l + freq[i] - k;
                    if (u < 0) continue;

                    // freq[i + 1]をk個に分割する組み合わせ
                    auto n_split = comb(freq[i] - 1, k - 1);
                    // j個の同じ文字が隣り合う箇所に分割したl個を挿入する組み合わせ
                    auto n_good_insert = comb(j, l);
                    // 全ての挿入可能な(len[i] + 1)箇所から同じ文字が隣り合っていない(len[i] + 1 - j)箇所のうち
                    // 分割した残りの(k - l)個を挿入する組み合わせ
                    auto n_bad_insert = comb(len + 1 - j, k - l);

                    (dp[i + 1][u] += dp[i][j] * n_split % MOD * n_good_insert % MOD * n_bad_insert % MOD) %= MOD;
                }
            }
        }

        len += freq[i];
    }

    return dp[n][0];
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
)");
#endif
    vector<int> freq;

    for (int i = 1; i <= MAX_N; ++i) {
        int temp;
        stream >> temp;
        if (0 < temp) freq.push_back(temp);
    }

    auto ans = solve(freq);
    cout << ans << endl;
    return 0;
}