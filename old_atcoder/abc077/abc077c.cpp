// https://beta.atcoder.jp/contests/abc077
// status: [solve][review]
// tag: [sort][binary_search]

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

const int MAX_N = 100000;
int N;
int A[MAX_N], B[MAX_N], C[MAX_N];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(6
3 14 159 2 6 53
58 9 79 323 84 6
2643 383 2 79 50 288
)");
    stringstream stream(program_input);
#endif
    stream >> N;
    for (int i = 0; i < N; ++i) stream >> A[i];
    for (int i = 0; i < N; ++i) stream >> B[i];
    for (int i = 0; i < N; ++i) stream >> C[i];

    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    ui64 ans = 0;
    for (auto i = 0; i < N; ++i) {
        auto na = distance(A, lower_bound(A, A + N, B[i]));
        auto nc = N - distance(C, upper_bound(C, C + N, B[i]));
        ans += na * nc;
    }

    cout << ans << endl;
    return 0;
}