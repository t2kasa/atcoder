// https://beta.atcoder.jp/contests/abc067

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

i64 sum[2 * 100000];

int main() {
    int n;
    cin >> n;
    i64 a;
    for (int i = 0; i < n; ++i) {
        cin >> a;

        sum[i] = a;
        if (i == 0) continue;
        sum[i] += sum[i - 1];
    }

    i64 ans = numeric_limits<i64>::max();
    for (int i = 0; i < n - 1; ++i) {
        i64 su = sum[i];
        i64 ara = sum[n - 1] - sum[i];
        i64 score = abs(su - ara);
        ans = min(ans, score);
    }
    cout << ans << endl;
    return 0;
}