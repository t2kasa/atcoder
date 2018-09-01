// https://beta.atcoder.jp/contests/abc088
// status: [solve]
// tag: [BFS]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_SIDE = 50;
const int NOT_VISITED = -1;

int H, W;
int sy, sx;
int gy, gx;
int dist[MAX_SIDE + 1][MAX_SIDE + 1];
char field[MAX_SIDE + 1][MAX_SIDE + 1];
int black_count;
queue<pair<int, int>> pos_queue;

bool is_goal(int y, int x) {
    return y == gy && x == gx;
}

void bfs(int y, int x) {
    pos_queue.push(make_pair(y, x));

    while (!pos_queue.empty()) {
        auto p = pos_queue.front();
        pos_queue.pop();

        y = p.first, x = p.second;
        auto up = y - 1, down = y + 1;
        auto left = x - 1, right = x + 1;

        // up
        if (1 <= up && field[up][x] != '#' && dist[up][x] == NOT_VISITED) {
            dist[up][x] = dist[y][x] + 1;
            if (is_goal(up, x)) break;
            pos_queue.push(make_pair(up, x));
        }

        // down
        if (down <= H && field[down][x] != '#' && dist[down][x] == NOT_VISITED) {
            dist[down][x] = dist[y][x] + 1;
            if (is_goal(down, x)) break;
            pos_queue.push(make_pair(down, x));
        }

        // left
        if (1 <= left && field[y][left] != '#' && dist[y][left] == NOT_VISITED) {
            dist[y][left] = dist[y][x] + 1;
            if (is_goal(y, left)) break;
            pos_queue.push(make_pair(y, left));
        }

        // right
        if (right <= W && field[y][right] != '#' && dist[y][right] == NOT_VISITED) {
            dist[y][right] = dist[y][x] + 1;
            if (is_goal(y, right)) break;
            pos_queue.push(make_pair(y, right));
        }
    }
}

void bfs() {
    memset(dist, NOT_VISITED, sizeof(dist));
    dist[sy][sx] = 0;
    bfs(sy, sx);
}


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(10 37
.....................................
...#...####...####..###...###...###..
..#.#..#...#.##....#...#.#...#.#...#.
..#.#..#...#.#.....#...#.#...#.#...#.
.#...#.#..##.#.....#...#.#.###.#.###.
.#####.####..#.....#...#..##....##...
.#...#.#...#.#.....#...#.#...#.#...#.
.#...#.#...#.##....#...#.#...#.#...#.
.#...#.####...####..###...###...###..
.....................................
)");

    stringstream stream(s);
#endif
    stream >> H >> W;
    black_count = 0;
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            stream >> field[y][x];
            if (field[y][x] == '#') black_count++;
        }
    }

    sy = 1, sx = 1;
    gy = H, gx = W;

    bfs();
    if (dist[gy][gx] == NOT_VISITED) cout << "-1" << endl;
    else {
        // (ゴールまでの移動マス数) = HW - (最初から黒のマスの数) - (最短経路のマス数) - (最初の1マス)
        auto ans = H * W - black_count - dist[gy][gx] - 1;
        cout << ans << endl;
    }
    return 0;
}