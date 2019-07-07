// https://beta.atcoder.jp/contests/atc001
// status: [solve]
// tag: [dfs]

#define SUBMIT

#include <sstream>
#include <iostream>

using namespace std;

const int MAX_SIDE = 500;

int H, W;
int sy, sx;
int gy, gx;
bool done[MAX_SIDE + 1][MAX_SIDE + 1];
char field[MAX_SIDE + 1][MAX_SIDE + 1];

void dfs(int y, int x) {
    if (y < 0 || x < 0 || H <= y || W <= x) return;
    if (field[y][x] == '#') return;
    if (done[y][x]) return;

    done[y][x] = true;

    dfs(y - 1, x);
    dfs(y + 1, x);
    dfs(y, x - 1);
    dfs(y, x + 1);
}


void start_dfs() {
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            done[y][x] = false;
        }
    }

    dfs(sy, sx);
}


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(10 10
s.........
#########.
#.......#.
#..####.#.
##....#.#.
#####.#.#.
g.#.#.#.#.
#.#.#.#.#.
#.#.#.#.#.
#.....#...
)");

    stringstream stream(s);
#endif
    stream >> H >> W;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            stream >> field[y][x];
            if (field[y][x] == 's') sy = y, sx = x;
            if (field[y][x] == 'g') gy = y, gx = x;
        }
    }

    start_dfs();

    if (done[gy][gx]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}