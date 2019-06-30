// https://beta.atcoder.jp/contests/abc115

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int ans = 0;
    int max_value = 0;
    for (int i = 0; i < n; ++i) {
        ans += p[i];
        max_value = max(max_value, p[i]);
    }
    ans -= max_value / 2;
    cout << ans << endl;
    return 0;
}