// https://beta.atcoder.jp/contests/abc072

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, t;
    cin >> x >> t;
    auto ans = max(x - t, 0);
    cout << ans << endl;
    return 0;
}