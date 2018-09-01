// https://beta.atcoder.jp/contests/abc099
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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 500;
const int MAX_C = 30;
const int NOT_VISITED = -1;

int D[MAX_C + 1][MAX_C + 1];
int color_count[3][MAX_C + 1];
// change_cost[i][j] (x + y) % 3 == iの要素を全てj色に変えたときのコスト
int change_cost[3][MAX_C + 1];

int N, C;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(4 3
0 12 71
81 0 53
14 92 0
1 1 2 1
2 1 1 2
2 2 1 3
1 1 2 2
)");
    stringstream stream(s);
#endif
    memset(color_count, 0, sizeof(color_count));
    memset(change_cost, 0, sizeof(change_cost));

    stream >> N >> C;
    for (int y = 1; y <= C; ++y) {
        for (int x = 1; x <= C; ++x) {
            stream >> D[y][x];
        }
    }

    int c;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            stream >> c;
            color_count[(x + y) % 3][c]++;
        }
    }

    for (int r = 0; r < 3; ++r) {
        for (int from = 1; from <= C; ++from) {
            for (int to = 1; to <= C; ++to) {
                change_cost[r][to] += color_count[r][from] * D[from][to];
            }
        }
    }

    // C色から3色を選ぶ全組み合わせから最小値を探す
    // 3 <= C <= 30なのでO(C^3)でもO(27000)
    int min_cost = numeric_limits<int>::max();
    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= C; ++j) {
            for (int k = 1; k <= C; ++k) {
                if (i == j || j == k || k == i) continue;
                min_cost = min(min_cost, change_cost[0][i] + change_cost[1][j] + change_cost[2][k]);
            }
        }
    }

#ifdef DEBUG
    cout << "each color count:" << endl;
    for (int r = 0; r < 3; ++r) {
        for (int from = 1; from <= C; ++from) {
            cout << color_count[r][from] << " ";
        }
        cout << endl;
    }

    cout << "change cost:" << endl;
    for (int r = 0; r < 3; ++r) {
        for (int to = 0; to <= C; ++to) {
            cout << change_cost[r][to] << " ";
        }
        cout << endl;
    }
#endif

    cout << min_cost << endl;
    return 0;
}