// https://beta.atcoder.jp/contests/abc066

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto ans = min<int>({a + b, b + c, c + a});
    cout << ans << endl;
    return 0;
}