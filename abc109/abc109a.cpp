// https://beta.atcoder.jp/contests/abc109

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(50
)");
#endif
    int A, B;
    stream >> A >> B;
    if (A % 2 == 1 && B % 2 == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}