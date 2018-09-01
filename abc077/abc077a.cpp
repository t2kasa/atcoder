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
    auto program_input = std::string(R"(eye
eel
)");
    stringstream stream(program_input);
#endif
    string s1, s2;
    stream >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    if (s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}