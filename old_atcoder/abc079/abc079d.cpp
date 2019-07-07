// https://beta.atcoder.jp/contests/abc079
// status: [solve]
// tag: [BFS][最短経路問題][ワーシャルフロイド]

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

const int MAX_C = 1000;
const int MAX_SIDE = 200;
const int N_NUMBER = 10;
const int NOT_VISITED = -1;

int c[N_NUMBER][N_NUMBER];
//int A[MAX_SIDE][MAX_SIDE];

// number_count[i] i (0 <= i <= 9)が出現する回数
int number_count[N_NUMBER];

// min_cost[i][j] iからj (0 <= i <= 9, 0 <= j <= 9)に変えるときの最小コスト
int min_cost[N_NUMBER][N_NUMBER];

int H, W;

void bfs(int start, int curr_i, int curr_cost) {
    if (c[start][curr_i] < curr_cost) return;

    min_cost[start][curr_i] = min(min_cost[start][curr_i], curr_cost);
//    cout << "cost: " << curr_cost << " transit: " << start << " -> " << curr_i << endl;
    for (int i = 0; i < N_NUMBER; ++i) {
        if (curr_i != i) bfs(start, i, curr_cost + c[curr_i][i]);
    }
}


void bfs() {
    for (int i = 0; i < N_NUMBER; ++i) {
        bfs(i, i, c[i][i]);
    }
}



int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(2 4
0 9 9 9 9 9 9 9 9 9
9 0 9 9 9 9 9 9 9 9
9 9 0 9 9 9 9 9 9 9
9 9 9 0 9 9 9 9 9 9
9 9 9 9 0 9 9 9 9 2
9 9 9 9 9 0 9 9 9 9
9 9 9 9 9 9 0 9 9 9
9 9 9 9 9 9 9 0 9 9
9 9 9 9 2 9 9 9 0 9
9 2 9 9 9 9 9 9 9 0
-1 -1 -1 -1
8 1 1 8
)");
    stringstream stream(s);
#endif
    // initialization
    for (int y = 0; y < N_NUMBER; ++y) {
        for (int x = 0; x < N_NUMBER; ++x) {
            if (y == x) min_cost[y][x] = 0;
            else min_cost[y][x] = MAX_C;
        }
    }
    memset(number_count, 0, sizeof(number_count));

    // inputs
    stream >> H >> W;
    for (int y = 0; y < N_NUMBER; ++y) {
        for (int x = 0; x < N_NUMBER; ++x) {
            stream >> c[y][x];
        }
    }
    int A;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            stream >> A;
            if (A != -1) number_count[A]++;
        }
    }

    bfs();
    int ans = 0;
    for (int i = 0; i < N_NUMBER; ++i) ans += min_cost[i][1] * number_count[i];
    cout << ans << endl;

#ifdef DEBUG
    cout << "number_count:" << endl;
    for (int i = 0; i < N_NUMBER; ++i) cout << number_count[i] << " ";
    cout << endl;

    cout << "min cost:" << endl;
    for (int i = 0; i < N_NUMBER; ++i) {
        for (int j = 0; j < N_NUMBER; ++j) {
            cout << min_cost[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}