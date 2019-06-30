// https://beta.atcoder.jp/contests/abc069
// status: [solve]
// tag:

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

int H, W, N;
int grid[100][100];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(2 2
3
2 1 1
)");
#endif
    stream >> H >> W;
    stream >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) stream >> a[i];

    int y = 0, x = 0;
    for (int i = 1; i <= N; ++i) {
        while (a[i] != 0) {
            if (y % 2 == 0) {
                auto n_paint = min(W - x, a[i]);
                for (int j = x; j < x + n_paint; ++j) grid[y][j] = i;
                a[i] -= n_paint;
                x += n_paint;
                if (x == W) y++, x = W - 1;
            }
            else {
                auto n_paint = min(x + 1 - 0, a[i]);
                for (int j = x; j > x - n_paint; --j) grid[y][j] = i;
                a[i] -= n_paint;
                x -= n_paint;
                if (x == -1) y++, x = 0;
            }
        }
    }

    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}