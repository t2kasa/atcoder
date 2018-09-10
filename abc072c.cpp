// https://beta.atcoder.jp/contests/abc072

#include <bits/stdc++.h>
using namespace std;

int c[100000 + 10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        c[a]++;
        c[a + 1]++;
        if (a != 0) c[a - 1]++;
    }

    auto ans = *max_element(c, c + 100000);
    cout << ans << endl;
    return 0;
}