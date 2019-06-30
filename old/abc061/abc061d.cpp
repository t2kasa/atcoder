// https://beta.atcoder.jp/contests/abc061
// status: [review]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

struct edge {
    edge(int dst, i64 w) : dst(dst), w(w) {}
    int dst;
    i64 w;
};

const int MAX_N = 1000;
vector<edge> e[MAX_N + 5];
i64 score[MAX_N + 5];
set<int> visited;
int N, M;

void bfs(int start) {
    queue<int> q;
    q.push(start);

    int prev = -1, curr = -1;
    while (!q.empty()) {
        curr = q.front(); q.pop();
        if (visited.find(curr) != visited.end()) {

        }
        visited.insert(curr);
        for (auto d : e[curr]) {
            if (d.dst == prev) continue;
            score[d.dst] = max(score[d.dst], score[curr] + d.w);
            q.push(d.dst);
        }
        prev = curr;
    }
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3 3
1 2 4
2 3 3
1 3 5
)");
#endif
    in >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i) {
        in >> a >> b >> c;
        e[a].emplace_back(b, c);
    }
    return 0;
}