// https://beta.atcoder.jp/contests/abc070

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Yes", string no = "No") { cout << (cond ? yes : no) << endl; }

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int left = max(a, c), right  = min(b, d);
    int ans = max(right - left, 0);
    cout << ans << endl;
    return 0;
}