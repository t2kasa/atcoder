// https://beta.atcoder.jp/contests/abc076
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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int N, K;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(10
10
)");
    stringstream stream(program_input);
#endif
    stream >> N >> K;

    ui64 ans = 1;
    while (N != 0) {
        ans = min(2 * ans, ans + K);
        N--;
    }

    cout << ans << endl;
    return 0;
}