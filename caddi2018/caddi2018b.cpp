// https://atcoder.jp/contests/caddi2018b

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    int ans = 0;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (h <= a && w <= b) ans++;
    }
    cout << ans << endl;

    return 0;
}