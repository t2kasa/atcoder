// https://beta.atcoder.jp/contests/abc079
// status: [solve]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(1234
)");
#endif
    char c[4];
    for (int i = 0; i < 4; ++i) stream >> c[i];

    set<char> s1 {c[0], c[1], c[2]};
    set<char> s2 {c[1], c[2], c[3]};

    if (s1.size() == 1 || s2.size() == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}