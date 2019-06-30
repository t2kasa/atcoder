// https://beta.atcoder.jp/contests/abc080
// status: [solve][review]

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

// 時間を引き伸ばす
// 各時刻で必要な録画機の数をカウントしたいが、時刻S - 0.5はそのままインデックスにはできないので2倍に引き伸ばす
template <typename T>
constexpr size_t extend_time(T time) { return static_cast<size_t>(2 * time); }
const int MAX_N = 100000;

int s[MAX_N], t[MAX_N], c[MAX_N];
// tt[time] timeで使用している録画機の台数
int tt[extend_time(MAX_N + 1)];
int sum[extend_time(MAX_N + 1)];
int N, C;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(9 4
56 60 4
33 37 2
89 90 3
32 43 1
67 68 3
49 51 3
31 32 3
70 71 1
11 12 3
)");
    stringstream stream(program_input);
#endif
    stream >> N >> C;
    for (int i = 0; i < N; ++i) stream >> s[i] >> t[i] >> c[i];

    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= C; ++i) {
        memset(tt, 0, sizeof(tt));

        for (int j = 0; j < N; ++j) {
            if (c[j] == i) {
                tt[extend_time(s[j] - 0.5)]++;
                tt[extend_time(t[j])]--;
            }
        }

        for (int j = 1; j < extend_time(MAX_N + 1) ; ++j) tt[j] += tt[j - 1];
        for (int j = 0; j < extend_time(MAX_N + 1); ++j) if (0 < tt[j]) sum[j]++;
    }

    auto ans = *max_element(sum, sum + (MAX_N + 1) * 2);
    cout << ans << endl;
    return 0;
}