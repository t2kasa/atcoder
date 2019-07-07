// https://beta.atcoder.jp/contests/abc080
// status: [solve]
// tag: [bit全探索]

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

const int MAX_K = 10;
const int MAX_N = 100;

int F[MAX_N][MAX_K];
int P[MAX_N][MAX_K + 1];
int n_opens[MAX_N + 1];
int N;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(2
1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1
0 -2 -2 -2 -2 -2 -1 -1 -1 -1 -1
0 -2 -2 -2 -2 -2 -1 -1 -1 -1 -1
)");
    stringstream stream(program_input);
#endif
    stream >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAX_K; ++j) {
            stream >> F[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAX_K + 1; ++j) {
            stream >> P[i][j];
        }
    }

    auto ans = numeric_limits<int>::min();
    // bit = 1で始めているのは必ず1つ以上の時間帯で店を盛業しなければならないため
    for (int bit = 1; bit < (1 << MAX_K); ++bit) {
        auto sum = 0;
        memset(n_opens, 0, sizeof(n_opens));

        for (int j = 0; j < MAX_K; ++j) {
            if (bit & (1 << j)) {
                for (int i = 0; i < N; ++i) n_opens[i] += F[i][j];
            }
        }

        for (int i = 0; i < N; ++i) sum += P[i][n_opens[i]];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}