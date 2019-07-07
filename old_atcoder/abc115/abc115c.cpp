// https://beta.atcoder.jp/contests/abc115

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(5 3
10
15
11
14
12
)");
#endif
    int n, k;
    in >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) in >> h[i];

    sort(h.begin(), h.end());

    int ans = INT_MAX;
    for (int i = 0; i < n - k + 1; ++i) {
        ans = min(ans, abs(h[i] - h[i + k - 1]));
    }
    cout << ans << endl;
    return 0;
}