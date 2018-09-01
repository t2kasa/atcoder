// https://beta.atcoder.jp/contests/abc075
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>
#include <numeric>
#include <limits>
#include <set>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 50;
int N, M;
bool adj[MAX_N][MAX_N];
bool done[MAX_N];
vector<pair<int, int>> edge;

void dfs(int i) {
    if (done[i]) return;
    done[i] = true;
    for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        if (adj[i][j]) dfs(j);
    }
}

int start_dfs() {
    auto ans = M;

    for (int e = 0; e < M; ++e) {
        adj[edge[e].first][edge[e].second] = false;
        adj[edge[e].second][edge[e].first] = false;
        for (int i = 0; i < N; ++i) done[i] = false;

        dfs(0);
        bool complete = true;
        for (int i = 0; i < N; ++i) {
            if (!done[i]) complete = false;
        }

        if (complete) ans--;

        adj[edge[e].first][edge[e].second] = true;
        adj[edge[e].second][edge[e].first] = true;
    }

    return ans;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(6 5
1 2
2 3
3 4
4 5
5 6
)");
    stringstream stream(program_input);
#endif
    stream >> N >> M;
    // initialization
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) adj[i][j] = true;
            else adj[i][j] = false;
        }
    }
    int a, b;
    for (int i = 0; i < M; ++i) {
        stream >> a >> b;
        edge.emplace_back(a - 1, b - 1);
        adj[a - 1][b - 1] = true;
        adj[b - 1][a - 1] = true;
    }

    auto ans = start_dfs();
    cout << ans << endl;

#ifdef DEBUG
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


    cout << "revisited:" << endl;
    for (auto r : revisited_nodes) cout << r << " ";
    cout << endl;

#endif
    return 0;
}