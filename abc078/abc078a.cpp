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
    auto program_input = std::string(R"(F F
)");
    stringstream stream(program_input);
#endif
    char X, Y;
    stream >> X >> Y;

    if (X < Y) cout << "<" << endl;
    else if (X > Y) cout << ">" << endl;
    else cout << "=" << endl;

    return 0;
}