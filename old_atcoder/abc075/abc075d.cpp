// https://beta.atcoder.jp/contests/abc075
// status: [review][solve]

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

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(4 3
-1000000000 -1000000000
1000000000 1000000000
-999999999 999999999
999999999 -999999999
)");
    stringstream stream(program_input);
#endif
    int N, K;
    stream >> N >> K;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) stream >> x[i] >> y[i];

    vector<int> x_sort(N), y_sort(N);
    copy(x.begin(), x.end(), x_sort.begin());
    copy(y.begin(), y.end(), y_sort.begin());

    sort(x_sort.begin(), x_sort.end());
    sort(y_sort.begin(), y_sort.end());

    ui64 ans = static_cast<ui64>(x_sort[N - 1] - x_sort[0]) * static_cast<ui64>(y_sort[N - 1] - y_sort[0]);
    for (int xi = 0; xi < N; ++xi) {
        for (int xj = xi + 1; xj < N; ++xj) {
            for (int yi = 0; yi < N; ++yi) {
                for (int yj = yi + 1; yj < N; ++yj) {
                    int n_contains = 0;

                    // 現在の長方形に含まれている点の個数を調べる
                    for (int i = 0; i < N; ++i) {
                        if (x_sort[xi] <= x[i] && x[i] <= x_sort[xj] && y_sort[yi] <= y[i] && y[i] <= y_sort[yj]) n_contains++;
                    }

                    if (K <= n_contains) ans = min(ans, static_cast<ui64>(x_sort[xj] - x_sort[xi]) * static_cast<ui64>(y_sort[yj] - y_sort[yi]));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}