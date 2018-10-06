// https://beta.atcoder.jp/contests/abc111

#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == '1') n[i] = '9';
        else n[i] = '1';
    }
    cout << n << endl;
    return 0;
}