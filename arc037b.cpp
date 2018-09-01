// https://beta.atcoder.jp/contests/arc037
// status: [solve][review]
// tag: [dfs]

// 木の判定方法
// DFSで直前ではないタイミングで訪問済みの頂点に再度訪れた場合は閉路があるので木ではない
// https://www.slideshare.net/chokudai/arc037


#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int NOT_GROUPED = -1;
const int MAX_N = 100;

int N, M;
int edge[MAX_N][MAX_N];
int node_group[MAX_N];

int n_groups;
int n_trees;

bool is_tree[MAX_N];

// latest_u: 直前のu
void dfs(int u, int latest_u) {
    if (node_group[u] != NOT_GROUPED) {
        is_tree[n_groups] = false;
        return;
    }

    node_group[u] = n_groups;
    for (int v = 0; v < N; ++v) {
        if (v != latest_u && edge[u][v]) dfs(v, u);
    }
}

void start_dfs() {
    n_groups = 0;
    for (int i = 0; i < N; ++i) {
        node_group[i] = NOT_GROUPED;
        is_tree[i] = true;
    }

    for (int u = 0; u < N; ++u) {
        if (node_group[u] == NOT_GROUPED) {
            dfs(u, -1);
            n_groups++;
        }
    }

    n_trees = 0;
    for (int i = 0; i < n_groups; ++i) {
        if (is_tree[i]) n_trees++;
    }
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(5 1
1 2
)");

    stringstream stream(s);
#endif
    memset(edge, 0, sizeof(edge));
    stream >> N >> M;
    int u, v;
    for (int i = 0; i < M; ++i) {
        stream >> u >> v;
        edge[u - 1][v - 1] = 1;
        edge[v - 1][u - 1] = 1;
    }

    start_dfs();
    cout << n_trees << endl;
    return 0;
}