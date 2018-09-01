// https://beta.atcoder.jp/contests/abc021
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using ui64 = uint64_t;
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto input = std::string(R"(9
)");
    stringstream stream(input);
#endif
    int N;
    stream >> N;

    auto u = 1 + (N - 1) / 2;
    cout << u << endl;
    if (N % 2 == 1) cout << "1" << endl;
    for (int i = 0; i < N / 2; ++i) cout << "2" << endl;

    return 0;
}