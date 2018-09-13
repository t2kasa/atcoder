// https://beta.atcoder.jp/contests/abc067

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> count_map;
    for (char c : s) count_map[c]++;

    int len = s.length();
    int ans;
    for (int back = 1; back < len; ++back) {
        if ((len - back) % 2 != 0) continue;
        int half = (len - back) / 2;

        bool ok = true;
        for (int i = 0; i < half; ++i) {
            if (s[i] != s[half + i]) ok = false;
        }

        if (ok) {
            ans = len - back;
            break;
        };
    }

    cout << ans << endl;
    return 0;
}