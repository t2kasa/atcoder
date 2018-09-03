// https://beta.atcoder.jp/contests/abc045
// status: [review][solve]

#define SUBMIT
//#define DEBUG
#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;

map<pair<int, int>, int> pos_to_count;
ui64 black_count[10];
ui64 H, W, N;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(1000000000 1000000000 0
)");
#endif
    stream >> H >> W >> N;
    int x, y;
    for (int i = 0; i < N; ++i) {
        stream >> y >> x;
        y--; x--;
        for (int r = y - 2; r <= y; ++r) {
            for (int c = x - 2; c <= x; ++c) {
                if (r < 0 || c < 0 || H - 2 <= r || W - 2 <= c) continue;
                pos_to_count[make_pair(r, c)]++;
            }
        }
    }

    for (const auto& p : pos_to_count) black_count[p.second]++;
    black_count[0] = (H - 2) * (W - 2) - pos_to_count.size();

    for (int i = 0; i < 10; ++i) cout << black_count[i] << endl;
    return 0;
}