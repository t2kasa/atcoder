// https://beta.atcoder.jp/contests/abc080
// status: [solve]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

void solve(int x) {
    int x_copy = x;
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }

    if (x_copy % sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(12
)");

    stringstream stream(s);
#endif
    int N;
    stream >> N;
    solve(N);
    return 0;
}