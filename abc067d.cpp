// https://beta.atcoder.jp/contests/abc067
// status: [review]
// tag: [bfs]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

const int INF = INT_MAX / 4;
const int MAX_N = 100000;
int N;
set<int> adj[MAX_N + 1];
bool done_black[MAX_N + 1];
bool done_white[MAX_N + 1];

int d_black[MAX_N + 1];
int d_white[MAX_N + 1];

void bfs(int s, int d[MAX_N + 1], bool done[MAX_N + 1]) {
    queue<int> q;
    d[s] = 0;
    done[s] = true;
    q.push(s);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (done[v]) continue;
            d[v] = d[u] + 1;
            done[v] = true;
            q.push(v);
        }
    }
}

void solve() {
    fill(d_black, d_black + MAX_N + 1, INF);
    fill(d_white, d_white + MAX_N + 1, INF);
    bfs(1, d_black, done_black);
    bfs(N, d_white, done_white);

    int n_black = 0, n_white = 0;
    for (int i = 1; i <= N; ++i) {
        if (d_black[i] <= d_white[i]) n_black++;
        else n_white++;
    }
    if (n_black <= n_white) cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(7
3 6
1 2
3 1
7 4
5 7
1 4
)");
#endif
    stream >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        stream >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    solve();
    return 0;
}