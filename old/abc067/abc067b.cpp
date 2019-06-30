// https://beta.atcoder.jp/contests/abc067

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Possible", string no = "Impossible") { cout << (cond ? yes : no) << endl; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> len(n);
    for (int i = 0; i < n; ++i) cin >> len[i];

    sort(len.begin(), len.end(), greater<>());
    auto ans = accumulate(len.begin(), len.begin() + k, 0);
    cout << ans << endl;
    return 0;
}