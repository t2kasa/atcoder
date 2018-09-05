// https://beta.atcoder.jp/contests/abc070
// status:
// tag: [BFS][DFS]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

const int MAX_N = 100000;
vector<int> adj[MAX_N + 1];
i64 d[MAX_N + 1];
bool done[MAX_N + 1];
map<pair<int, int>, i64> cost;
int N, Q, K;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    done[s] = true;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (done[v]) continue;

            d[v] = d[u] + cost[make_pair(u, v)];
            q.push(v);
            done[v] = true;
        }
    }
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(5
1 2 1
2 3 2
1 4 3
4 5 4
2 5
3 4
1 3
)");
#endif
    stream >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        i64 c;
        stream >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[make_pair(a, b)] = c;
        cost[make_pair(b, a)] = c;
    }

    stream >> Q >> K;
    bfs(K);

    for (int q = 0; q < Q; ++q) {
        int x, y;
        stream >> x >> y;
        auto ans = d[x] + d[y];
        cout << ans << endl;
    }
#ifdef DEBUG
    cout << "floyd" << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << d[y][x] << " ";
        }
        cout << endl;
    }

    cout << "input" << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << A[y][x] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}