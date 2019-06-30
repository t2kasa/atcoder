// https://beta.atcoder.jp/contests/abc063

#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> cs;
    string s;
    cin >> s;
    for (auto c : s) {
        if (cs.find(c) != cs.end()) {
            cout << "no" << endl;
            exit(0);
        }
        cs.insert(c);
    }
    cout << "yes" << endl;
    return 0;
}