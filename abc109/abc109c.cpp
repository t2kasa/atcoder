// https://beta.atcoder.jp/contests/abc109

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (0 < y) {
        auto r = x % y;
        x = y, y = r;
    }

    return x;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(1 1
1000000000
)");
#endif
    int N, X;
    stream >> N >> X;
    int ans = INT_MAX;
    int min_dist = INT_MAX;
    for (int i = 0; i < N; ++i) {
        int x;
        stream >> x;
        min_dist = min(min_dist, abs(X - x));
        auto g = gcd(abs(X - x), min_dist);
        ans = min(ans, g);
    }
    cout << ans << endl;
    return 0;
}