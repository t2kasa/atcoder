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

const int MAX_SIDE = 50;
char field[MAX_SIDE][MAX_SIDE];
int ans[MAX_SIDE][MAX_SIDE];
int H, W;


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(6 6
#####.
#.#.##
####.#
.#..#.
#.##..
#.#...
)");
    stringstream stream(program_input);
#endif
    stream >> H >> W;
    memset(ans, 0, sizeof(ans));
    // initialization
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            stream >> field[y][x];

            if (field[y][x] == '#') {
                for (int r = max(0, y - 1); r <= min(H - 1, y + 1); ++r) {
                    for (int c = max(0, x - 1); c <= min(W - 1, x + 1); ++c) {
                        ans[r][c]++;
                    }
                }
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (field[y][x] == '#') cout << '#';
            else cout << ans[y][x];
        }
        cout << endl;
    }

#ifdef DEBUG
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cout << ans[y][x] <<  " ";
        }
        cout << endl;
    }
#endif
    return 0;
}