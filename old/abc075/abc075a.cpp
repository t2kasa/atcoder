// https://beta.atcoder.jp/contests/abc075
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
#include <set>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(-100 100 100
)");
    stringstream stream(program_input);
#endif
    int A, B, C;
    stream >> A >> B >> C;
    if (A == B) cout << C << endl;
    else if (B == C) cout << A << endl;
    else cout << B << endl;

    return 0;
}