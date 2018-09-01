// https://beta.atcoder.jp/contests/abc078
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

const int MAX_N = 2000;
int N, Z, W;
int a[MAX_N];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(3 100 1000
10 100 100
)");
    stringstream stream(program_input);
#endif
    stream >> N >> Z >> W;
    for (int i = 0; i < N; ++i) stream >> a[i];

    if (N == 1) cout << abs(a[0] - W) << endl;
    else cout << max(abs(a[N - 1] - W), abs(a[N - 2] - a[N - 1])) << endl;
    return 0;
}