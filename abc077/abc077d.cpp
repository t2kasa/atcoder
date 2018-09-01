// https://beta.atcoder.jp/contests/abc077
// status: [review][solve]
// tag: [01BFS]

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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_K = 100000;
const int INF = 1 << 20;
int K;
int dist[MAX_K];

// (i-th node, distance) pair
deque<pair<int, int>> q;

int bfs() {
    // 重みつきグラフで重みが0 or 1のみの場合 0-1 BFSで効率的にBFSが可能
    q.push_back(make_pair(1, 0));

    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();

        if (dist[p.first] != INF) continue;
        dist[p.first % K] = p.second;
        if (p.first == 0) break;

        q.push_back(make_pair((p.first + 1) % K, p.second + 1));
        q.push_front(make_pair((p.first * 10) % K, p.second));
    }

    return dist[0] + 1;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(6
)");
    stringstream stream(program_input);
#endif
    stream >> K;
    for (int i = 0; i < K; ++i) dist[i] = INF;

    auto ans = bfs();
    cout << ans << endl;
    return 0;
}