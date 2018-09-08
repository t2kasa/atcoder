// https://beta.atcoder.jp/contests/abc109

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

int a[500 + 1][500 + 1];
int H, W;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(2 3
1 2 3
0 1 1
)");
#endif
    stream >> H >> W;
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            stream >> a[y][x];
        }
    }

    vector<string> ans;
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            if (y == H && x == W) continue;

            if (a[y][x] % 2 == 1) {
                a[y][x]--;

                stringstream ss;
                // move right or down if odd
                if (x < W) {
                    a[y][x + 1]++;
                    ss << y << " " << x << " " << y << " " << (x + 1);
                }
                else {
                    a[y + 1][x]++;
                    ss << y << " " << x << " " << (y + 1) << " " << x;
                }

                ans.push_back(ss.str());
            }
        }
    }

    cout << ans.size() << endl;
    for (auto s : ans) cout << s << endl;
#ifdef DEBUG
    cout << "debug" << endl;
    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x) {
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}