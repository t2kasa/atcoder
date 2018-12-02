// https://beta.atcoder.jp/contests/abc114

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    auto ans = INT_MAX;
    for (int i = 0; i < s.length() - 2; ++i) ans = min(ans, abs(753 - stoi(s.substr(i, 3))));
    cout << ans << endl;
    return 0;
}