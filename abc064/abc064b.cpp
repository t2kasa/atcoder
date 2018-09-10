// https://beta.atcoder.jp/contests/abc070

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    auto ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    cout << ans << endl;
    return 0;
}