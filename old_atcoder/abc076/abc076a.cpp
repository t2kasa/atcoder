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

double R, G;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(4500
0
)");
    stringstream stream(program_input);
#endif
    stream >> R >> G;
    cout << (2 * G - R) << endl;
    return 0;
}