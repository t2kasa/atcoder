#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(35897 932
)");
#endif
    ui64 ans = 0;
    i64 N, K;
    stream >> N >> K;

    for (int a = 1; a <= N; ++a) {
        i64 r = a / K;
        i64 b = (r + 1) * K - a;
        if (abs(a - b) % K != 0) continue;

        i64 c = min<i64>({a, b, K});
        i64 u = 1 + (N - b) / K;
        i64 v = 1 + (N - c) / K;
        ans += u * v;
    }

    cout << ans << endl;
    return 0;
}