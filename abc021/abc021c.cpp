// https://beta.atcoder.jp/contests/abc021
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using ui64 = uint64_t;
using namespace std;

const ui64 INF = 1 << 28;
const ui64 MOD =  1000000007;
const int MAX_N = 100;
ui64 a, b;
ui64 ans;
ui64 N, M;
ui64 adj[MAX_N][MAX_N];
ui64 n_min_path[MAX_N];
ui64 dist[MAX_N];

queue<ui64> q;

void bfs(ui64 goal) {
    while (!q.empty()) {
        auto i = q.front(); q.pop();

        for (ui64 j = 0; j < N; ++j) {
            if (i == j) continue;
            if (!adj[i][j]) continue;

            // より短い経路が見つかった
            if (dist[i] + 1 < dist[j]) n_min_path[j] = n_min_path[i];
            // 現在の最短経路と同じ距離
            else if (dist[i] + 1 == dist[j]) n_min_path[j] = (n_min_path[j] + n_min_path[i]) % MOD;
            // 上記の2つでない場合は現在の最短経路よりも長いので何もしない

            if (dist[j] == INF) q.push(j);
            dist[j] = min(dist[j], dist[i] + 1);
        }
    }
}


void run_bfs(ui64 start, ui64 goal) {
    for (int i = 0; i < MAX_N; ++i) dist[i] = INF;
    dist[start] = 0;
    n_min_path[start] = 1;

    q.push(start);
    bfs(goal);
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto input = std::string(R"(7
1 7
8
1 2
1 3
4 2
4 3
4 5
4 6
7 5
7 6
)");
    stringstream stream(input);
#endif
    stream >> N;
    stream >> a >> b;
    stream >> M;
    a -= 1, b -= 1;

    ui64 p, r;
    for (int i = 0; i < M; ++i) {
        stream >> p >> r;
        adj[p - 1][r - 1] = 1;
        adj[r - 1][p - 1] = 1;
    }

    run_bfs(a, b);
    cout << n_min_path[b] << endl;
    return 0;
}