// https://beta.atcoder.jp/contests/abc074
// status:

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(5
20
11 12 9 17 12
)");
#endif
    int N, K;
    stream >> N >> K;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        stream >> a;
        ans += 2 * min(abs(a - 0), abs(a - K));
    }
    cout << ans << endl;
    return 0;
}