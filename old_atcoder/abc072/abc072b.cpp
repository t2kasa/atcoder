// https://beta.atcoder.jp/contests/abc072

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.length(); i += 2) ans += s[i];
    cout << ans << endl;
    return 0;
}