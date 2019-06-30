#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(9 10
0 3 5 7 100 110 200 300 311
)");
#endif
    int N, T;

    in >> N >> T;

    vector<int> t(N);
    for (int i = 0; i < N; ++i) in >> t[i];

    int64_t ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (t[i + 1] - t[i] < T) ans += t[i + 1] - t[i];
        else ans += T;
    }
    ans += T;
    cout << ans << endl;
    return 0;
}