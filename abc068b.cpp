// https://beta.atcoder.jp/contests/abc068

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans;
    int max_div = -1;
    for (int i = 1; i <= n; ++i) {
        int x = i;
        int div = 0;
        while (x % 2 == 0) {
            div++;
            x /= 2;
        }

        if (max_div < div) {
            max_div = div;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}