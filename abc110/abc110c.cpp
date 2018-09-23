// https://beta.atcoder.jp/contests/abc110
// status: [review]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(azzel
apple
)");
#endif
    string S, T;
    in >> S >> T;

    bool ok = true;
    map<char, char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        auto s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ok = false;
        if (ima.count(t)) if (ima[t] != s) ok = false;
        ma[s] = t, ima[t] = s;
    }
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}