// https://beta.atcoder.jp/contests/abc079
// status: [solve]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const ui64 MAX_N = 86;
ui64 lu[MAX_N + 1];

void init_lucas_number() {
    lu[0] = 2;
    lu[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) lu[i] = lu[i - 1] + lu[i - 2];
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(5
)");
#endif
    init_lucas_number();
    int N;
    stream >> N;
    cout << lu[N] << endl;
    return 0;
}