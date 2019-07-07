// https://beta.atcoder.jp/contests/abc007
// status: [solve]

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

int R, C;
int sy, sx;
int gy, gx;
int dist[MAX_SIDE + 1][MAX_SIDE + 1];
char field[MAX_SIDE + 1][MAX_SIDE + 1];
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
        if (down <= R && field[down][x] != '#' && dist[down][x] == NOT_VISITED) {
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
        if (right <= C && field[y][right] != '#' && dist[y][right] == NOT_VISITED) {
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
    auto s = std::string(R"(7 8
2 2
4 5
########
#......#
#.######
#..#...#
#..##..#
##.....#
########)");

    stringstream stream(s);
#endif
    stream >> R >> C;
    stream >> sy >> sx;
    stream >> gy >> gx;

    for (int y = 1; y <= R; ++y) {
        for (int x = 1; x <= C; ++x) {
            stream >> field[y][x];
        }
    }

    bfs();
    cout << dist[gy][gx] << endl;
    return 0;
}