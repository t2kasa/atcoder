// https://beta.atcoder.jp/contests/abc068
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(50
)");
#endif
    ui64 K, N;
    stream >> K;

    if (K == 0) {
        cout << "2" << endl;
        cout << "0 0" << endl;
        exit(0);
    }
    if (K == 1) {
        cout << "2" << endl;
        cout << "0 2" << endl;
        exit(0);
    }

    const ui64 MAX_N = 50;
    N = min(K, MAX_N);

    ui64 r = K / N;
    ui64 rest = K - r * N;

    cout << N << endl;
    vector<ui64> d;
    for (int i = 1; i <= N; ++i) {
        ui64 a = r + (i - 1);
        if (N - i < rest) a++;

        d.push_back(a);
        cout << a;
        if (i != N) cout << " ";
        else cout << endl;
    }
#ifdef DEBUG
    ui64 actual = 0;
    while (true) {
        auto found = max_element(d.begin(), d.end());
        if (*found < N) break;

        actual++;
        for (int i = 0; i < N; ++i) d[i]++;
        *found -= N + 1;
    }
    cout << actual << endl;
#endif
    return 0;
}