// https://beta.atcoder.jp/contests/abc073
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(2
6 8
3 3
)");
#endif
    int N;
    int ans = 0;
    stream >> N;
    for (int i = 0; i < N; ++i) {
        int left, right;
        stream >> left >> right;
        ans += 1 + (right - left);
    }
    cout << ans << endl;
    return 0;
}