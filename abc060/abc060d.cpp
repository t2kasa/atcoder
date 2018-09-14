// https://beta.atcoder.jp/contests/abc060
// status: [review]
// tag: [DP]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

i64 sum_v[4][100 + 1];

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(4 6
2 1
3 4
4 10
3 4
)");
#endif
    int N, W;
    in >> N >> W;

    vector<i64> v[4];
    i64 wi, vi, w1;
    for (int i = 0; i < N; ++i) {
        in >> wi >> vi;
        if (i == 0) w1 = wi;
        v[wi - w1].push_back(vi);
    }

    for (int i = 0; i < 4; ++i) {
        sort(v[i].begin(), v[i].end(), greater<>());
        for (int j = 1; j <= v[i].size(); ++j) {
            sum_v[i][j] += v[i][j - 1] + sum_v[i][j - 1];
        }
    }

    i64 ans = 0;
    for (int a = 0; a <= v[0].size(); ++a) {
        for (int b = 0; b <= v[1].size(); ++b) {
            for (int c = 0; c <= v[2].size(); ++c) {
                for (int d = 0; d <= v[3].size(); ++d) {
                    i64 w_k = (w1 + 0) * a + (w1 + 1) * b + (w1 + 2) * c + (w1 + 3) * d;
                    if (W < w_k) continue;
                    i64 v_k = sum_v[0][a] + sum_v[1][b] + sum_v[2][c] + sum_v[3][d];
                    ans = max(ans, v_k);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}