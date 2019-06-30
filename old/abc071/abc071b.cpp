// https://beta.atcoder.jp/contests/abc071

#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> chars;
    for (char c = 'a'; c <= 'z'; c++) chars.insert(c);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (chars.find(s[i]) != chars.end()) chars.erase(s[i]);
    }

    if (!chars.empty()) cout << *chars.begin() << endl;
    else cout << "None" << endl;

    return 0;
}