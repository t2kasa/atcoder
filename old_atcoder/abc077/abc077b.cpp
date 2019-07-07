// https://beta.atcoder.jp/contests/abc077
// status: [solve]
// tag:

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

int N;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(10
)");
    stringstream stream(program_input);
#endif
    stream >> N;
    int s = static_cast<int>(sqrt(N));
    int ans = s * s;
    cout << ans << endl;
    return 0;
}