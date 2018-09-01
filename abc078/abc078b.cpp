// https://beta.atcoder.jp/contests/abc078
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

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(64145 123 456
)");
    stringstream stream(program_input);
#endif
    int X, Y, Z;
    stream >> X >> Y >> Z;

    // ans = aとすると以下を満たす最大のaを求めれば良い
    // aY + (a + 1)Z <= X
    // a <= (X - Z) / (Y + Z)

    auto ans = (X - Z) / (Y + Z);
    cout << ans << endl;
    return 0;
}