// https://beta.atcoder.jp/contests/abc072
// status: [solve][review]
// tag:

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>

using namespace std;
using ui64 = uint64_t;

int p[100000 + 10];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(5
1 4 3 5 2
)");
#endif
    int N;
    stream >> N;
    for (int i = 1; i <= N; ++i) stream >> p[i];

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (p[i] == i) {
            if (i != N) swap(p[i + 1], p[i]);
            else swap(p[i - 1], p[i]);
            ans++;
        }
    }

    cout << ans << endl;
#ifdef DEBUG
    for (int i = 1; i <= N; ++i) cout << p[i] << " ";
    cout << endl;
#endif
    return 0;
}