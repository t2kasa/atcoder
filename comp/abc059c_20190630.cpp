#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int64_t solve(vector<int64_t>& a) {
    int64_t res = 0;
    int64_t sum = 0;
    for (int64_t i = 0; i < a.size(); ++i) {
        if (i % 2 == 0) {
            if (sum + a[i] <= 0) {
                res += abs(sum + a[i] - 1);
                sum = 1;
            } else {
                sum += a[i];
            }
        }
        else {
            if (sum + a[i] >= 0) {
                res += abs(sum + a[i] + 1);
                sum = -1;
            } else {
                sum += a[i];
            }
        }
    }

    return res;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6
-1 4 3 2 -5 4
)");
#endif
    size_t n;
    in >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) in >> a[i];

    int64_t ans = solve(a);
    for (int i = 0; i < n; ++i) a[i] *= -1;
    ans = min(ans, solve(a));
    cout << ans << endl;
    return 0;
}