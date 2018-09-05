// https://beta.atcoder.jp/contests/abc071
// status: [solve]
// tag:

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>

using namespace std;
using ui64 = uint64_t;

const ui64 MOD = 1000000007;

int N;
char s[2][52];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(52
RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn
RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn
)");
#endif
    int N;
    stream >> N;
    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < N; ++x) {
            stream >> s[y][x];
        }
    }

    string prev = "none";
    // 最初の色は3通り
    uint64_t ans = 1 * 3;
    int x = 0;
    while (true) {
        if (N <= x) break;

        // 2x1のドミノ
        if (s[0][x] == s[1][x]) {
            if (prev == "v") (ans *= 2) %= MOD;
            else (ans *= 1) %= MOD;

            x++;
            prev = "v";
        }
        // 1x2のドミノ
        else {
            if (prev == "h") (ans *= 3) %= MOD;
            else (ans *= 2) %= MOD;

            x += 2;
            prev = "h";
        }
    }

    cout << ans << endl;
#ifdef DEBUG
    for (int i = 1; i <= N; ++i) cout << p[i] << " ";
    cout << endl;
#endif
    return 0;
}