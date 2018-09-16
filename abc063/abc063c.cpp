// https://beta.atcoder.jp/contests/abc063

#include <bits/stdc++.h>
using namespace std;

int s[100];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> s[i];

    sort(s, s + N);
    auto sum = accumulate(s, s + N, 0);
    if (sum % 10 != 0) {
        cout << sum << endl;
        exit(0);
    }

    int first_not_10x_index = 0;
    while (first_not_10x_index != N && s[first_not_10x_index] % 10 == 0) first_not_10x_index++;

    auto ans = (first_not_10x_index == N) ? 0 : sum - s[first_not_10x_index];
    cout << ans << endl;
    return 0;
}