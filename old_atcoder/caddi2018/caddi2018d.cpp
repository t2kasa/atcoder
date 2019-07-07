// https://atcoder.jp/contests/caddi2018b

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3
100000
30000
20000
)");
#endif
    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) in >> a[i];

    auto all_even = true;
    for (int j = 0; j < n; ++j) {
        if (a[j] % 2 == 1) {
            all_even = false;
        }
    }

    cout << (all_even ? "second" : "first") << endl;
    return 0;
}