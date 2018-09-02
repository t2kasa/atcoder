// https://beta.atcoder.jp/contests/abc080
// status: [solve]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(7 17 120
)");

    stringstream stream(s);
#endif
    int N, A, B;
    stream >> N >> A >> B;
    auto ans = min(A * N, B);
    cout << ans << endl;
    return 0;
}