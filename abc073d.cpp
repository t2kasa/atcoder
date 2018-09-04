// https://beta.atcoder.jp/contests/abc073
// status: [solve][review]
// tag: [ワーシャルフロイド]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>

using namespace std;
using ui64 = uint64_t;

// MEMO: INFの設定値が小さすぎたためにWA
const int INF = INT_MAX / 4;
const int MAX_N = 200;
const int MAX_R = 8;
int r[MAX_R];
int d[MAX_N][MAX_N];
int N, M, R;

void floyd() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void init() {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(3 3 3
1 2 3
1 2 1
2 3 1
3 1 4
)");
#endif
    init();
    stream >> N >> M >> R;
    for (int i = 0; i < R; ++i) {
        int r_i;
        stream >> r_i;
        r[i] = r_i - 1;
    }
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        stream >> A >> B >> C;
        d[A - 1][B - 1] = d[B - 1][A - 1] = C;
    }

    floyd();

    int ans = INF;
    sort(r, r + R);
    do {
        int dist = 0;
        for (int i = 1; i < R; ++i) dist += d[r[i - 1]][r[i]];
        ans = min(ans, dist);
    } while (next_permutation(r, r + R));

    cout << ans << endl;
#ifdef DEBUG
    cout << "floyd" << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << d[y][x] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}