// https://beta.atcoder.jp/contests/abc091
// status: [review][solve]

// MEMO
// コンテナxに対して[A, B)を満たす要素数を求めたいときは
// upper_bound(x.begin(), x.end(), B - 1) - lower_bound(x.begin(), x.end(), A)
// upper_boundを使う時にB - 1にするのを忘れないように注意する

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
int a[MAX_N];
int b[MAX_N];

long solve(int N) {
    auto ans = 0;
    for (int v = (1 << 28); v; v >>=1) {
        for (int i = 0; i < N; ++i) a[i] &= 2 * v - 1;
        for (int i = 0; i < N; ++i) b[i] &= 2 * v - 1;
        sort(a, a + N); sort(b, b + N);

        long t = 0;
        for (int i = 0; i < N; ++i) {
            long t1_to_t2 = upper_bound(b, b + N, 2 * v - a[i] - 1) - lower_bound(b, b + N, 1 * v - a[i]);
            long t3_to_t4 = upper_bound(b, b + N, 4 * v - a[i] - 1) - lower_bound(b, b + N, 3 * v - a[i]);
            t += t1_to_t2 + t3_to_t4;
            t &= 1;
        }
        if (t) ans += v;
    }

    return ans;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(1
0
0
)");
#endif
    int N;
    stream >> N;
    for (int i = 0; i < N; ++i) stream >> a[i];
    for (int i = 0; i < N; ++i) stream >> b[i];
    auto ans = solve(N);
    cout << ans << endl;
    return 0;
}