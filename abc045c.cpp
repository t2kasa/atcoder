// https://beta.atcoder.jp/contests/abc045
// status: [solve]

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(9999999999
)");
#endif
    string S;
    stream >> S;

    ll ans = 0;
    ll len = S.length();
    for (int bit = 0; bit < (1 << (len - 1)); ++bit) {
        int prev_i = 0;
        ll sum = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (bit & (1 << i)) {
                sum += atoll(S.substr(prev_i, i + 1 - prev_i).c_str());
                prev_i = i + 1;
            }
        }

        sum += atoll(S.substr(prev_i, len - prev_i).c_str());
        ans += sum;
    }

    cout << ans << endl;
    return 0;
}