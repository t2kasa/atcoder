// https://beta.atcoder.jp/contests/abc116

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(begin(a), end(a));
    auto ans = a[0] * a[1] / 2;
    cout << ans << endl;
    return 0;
}