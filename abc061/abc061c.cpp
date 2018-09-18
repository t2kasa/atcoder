// https://beta.atcoder.jp/contests/abc061

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

ui64 N, K;
map<int, ui64> int_to_count;

int main() {
    cin >> N >> K;
    ui64 a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        int_to_count[a] += b;
    }

    int ans = 0;
    ui64 sum = 0;
    for (auto p : int_to_count) {
        sum += p.second;
        if (K <= sum) {
            ans = p.first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}