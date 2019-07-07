// https://beta.atcoder.jp/contests/abc110

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end(), greater<>());
    auto ans = 10 * v[0] + v[1] + v[2];
    cout << ans << endl;
    return 0;
}