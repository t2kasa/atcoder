// https://atcoder.jp/contests/caddi2018b

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;
using ui64 = uint64_t;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(1 1000
)");
#endif
    ui64 n, p;
    in >> n >> p;

    if (n == 1) {
        cout << p << endl;
        exit(0);
    }

    if (64 <= n) {
        cout << 1 << endl;
        exit(0);
    }

    ui64 ans = 1;
    for (ui64 i = 1; i <= p; ++i) {
        bool break_flag = false;
        ui64 y = 1;
        for (int j = 0; j < n; ++j) {
            y *= i;
            if (p < y) {
                break_flag = true;
                break;
            }
        }

        if (break_flag) break;
        if (p % y == 0) ans = i;
    }
    cout << ans << endl;
    return 0;
}