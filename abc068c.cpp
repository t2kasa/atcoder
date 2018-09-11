// https://beta.atcoder.jp/contests/abc068

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "POSSIBLE", string no = "IMPOSSIBLE") { cout << (cond ? yes : no) << endl; }

const int MAX_N = 200000;
int N, M;
set<int> adj[MAX_N + 1];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(5 5
1 3
4 5
2 3
2 4
1 4
)");
#endif
    int N, M;
    stream >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i) {
        stream >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    bool possible = false;
    set<int> reachable_nodes;
    for (auto u : adj[1]) reachable_nodes.insert(u);
    for (auto r : reachable_nodes) {
        if (adj[r].find(N) != adj[r].end()) {
            possible = true;
            break;
        }
    }

    print_yes_no(possible);
    return 0;
}