// https://beta.atcoder.jp/contests/abc111

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    auto x = n / 100;
    if (n > 100 * x + 10 * x + x) x++;
    auto ans = 100 * x + 10 * x + x;
    cout << ans << endl;
    return 0;
}