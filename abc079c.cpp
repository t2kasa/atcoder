// https://beta.atcoder.jp/contests/abc079
// status: [solve]
// tag: [全探索]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int N = 3;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(3242
)");
#endif
    char cs[4];
    int v[4];
    for (int i = 0; i < 4; ++i) stream >> cs[i];
    for (int i = 0; i < 4; ++i) v[i] = cs[i] - '0';

    for (int bit = 0; bit < (1 << N); ++bit) {
        string ans = to_string(v[0]);
        int sum = v[0];
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                sum += v[i + 1];
                ans += "+";
            }
            else {
                sum -= v[i + 1];
                ans += "-";
            }
            ans += to_string(v[i + 1]);
        }
        if (sum == 7) {
            ans += "=7";
            cout << ans << endl;
            break;
        }
    }
    return 0;
}