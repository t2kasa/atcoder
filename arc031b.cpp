// https://beta.atcoder.jp/contests/arc031
// status: [solve]
// tag: [dfs]

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
const int MAX_SIDE = 10;

const char LAND = 'o';
const char SEA = 'x';
char original_field[MAX_SIDE][MAX_SIDE];
char field[MAX_SIDE][MAX_SIDE];
int group[MAX_SIDE][MAX_SIDE];

int n_groups;

void dfs(int y, int x) {
    if (y < 0 || MAX_SIDE <= y || x < 0 || MAX_SIDE <= x) return;
    if (field[y][x] == SEA) return;
    if (group[y][x] != NOT_GROUPED) return;

    group[y][x] = n_groups;
    dfs(y - 1, x);
    dfs(y + 1, x);
    dfs(y, x - 1);
    dfs(y, x + 1);
}

void reset_state() {
    n_groups = 0;
    memcpy(field, original_field, sizeof(original_field));
    for (int r = 0; r < MAX_SIDE; ++r) {
        for (int c = 0; c < MAX_SIDE; ++c) {
            group[r][c] = NOT_GROUPED;
        }
    }
}

bool start_dfs() {
    for (int y = 0; y < MAX_SIDE; ++y) {
        for (int x = 0; x < MAX_SIDE; ++x) {
            reset_state();
            field[y][x] = LAND;

            for (int r = 0; r < MAX_SIDE; ++r) {
                for (int c = 0; c < MAX_SIDE; ++c) {
                    if (field[r][c] == LAND && group[r][c] == NOT_GROUPED) {
                        dfs(r, c);
                        n_groups++;
                    }
                }
            }

            if (n_groups == 1) return true;
        }
    }

    return false;
}


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(xxxxoxxxxx
xxxxoxxxxx
xxxxoxxxxx
xxxxoxxxxx
ooooxooooo
xxxxoxxxxx
xxxxoxxxxx
xxxxoxxxxx
xxxxoxxxxx
xxxxoxxxxx
)");

    stringstream stream(s);
#endif
    for (int y = 0; y < MAX_SIDE; ++y) {
        for (int x = 0; x < MAX_SIDE; ++x) {
            stream >> original_field[y][x];
        }
    }

    if (start_dfs()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}