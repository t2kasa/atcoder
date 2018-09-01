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
#include <cmath>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(100 5
)");
    stringstream stream(program_input);
#endif
    int N, M;
    stream >> N >> M;
    auto ans = (1900 * M + 100 * (N - M)) * pow(2, M);
    cout << ans << endl;
    return 0;
}