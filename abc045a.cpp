// https://beta.atcoder.jp/contests/abc045
// status: [solve]

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, h;
    cin >> a >> b >> h;
    auto ans = (a + b) * h / 2;
    cout << ans << endl;
    return 0;
}