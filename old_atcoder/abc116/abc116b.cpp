// https://beta.atcoder.jp/contests/abc116

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    return (n % 2 == 0) ? (n / 2) : (3 * n + 1);
}

int main() {
    int s;
    cin >> s;
    set<int> a;
    a.insert(s);

    int ans = 1;
    while (true) {
        s = f(s);
        ans++;
        if (a.count(s)) break;
        else a.insert(s);
    }

    cout << ans << endl;
    return 0;
}