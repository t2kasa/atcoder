// https://beta.atcoder.jp/contests/abc110

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xs(n), ys(m);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    for (int i = 0; i < m; ++i) cin >> ys[i];

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    bool no_war = false;
    for (int i = x + 1; i <= y; ++i) {
        if (lower_bound(xs.begin(), xs.end(), i) != xs.end()) continue;
        if (upper_bound(ys.begin(), ys.end(), i - 1) != ys.begin()) continue;
        no_war = true;
        break;
    }

    if (no_war) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}