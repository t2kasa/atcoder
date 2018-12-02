#define SUBMIT

#include <bits/stdc++.h>

using namespace std;


int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6
3
1
4
1
5
9
)");
#endif
    int64_t n;
    in >> n;
    vector<uint64_t> a(n);
    for (int64_t i = 0; i < n; ++i) in >> a[i];
    sort(a.begin(), a.end());

    int64_t half = (n - 1) / 2;

    uint64_t ans = 0;
    // even
    if (n % 2 == 0) {
        uint64_t min_sum1 = 2 * accumulate(a.begin(), a.begin() + half + 1, 0u) - a[half];
        uint64_t max_sum1 = 2 * accumulate(a.begin() + half + 1, a.end(), 0u) - a[half + 1];

        uint64_t min_sum2 = 2 * accumulate(a.begin(), a.begin() + half + 1, 0u) - a[half];
        uint64_t max_sum2 = 2 * accumulate(a.begin() + half + 1, a.end(), 0u) - a[half + 1];
        ans = max(max_sum2 - min_sum2, max_sum1 - min_sum1);
    }
    // odd
    else {
        uint64_t min_sum1 = 2 * accumulate(a.begin(), a.begin() + half, 0u);
        uint64_t max_sum1 = 2 * accumulate(a.begin() + half, a.end(), 0u) - a[n - 1] - a[n - 2];

        uint64_t min_sum2 = 2 * accumulate(a.begin(), a.begin() + half + 1, 0u) - a[half] - a[half - 1];
        uint64_t max_sum2 = 2 * accumulate(a.begin() + half + 1, a.end(), 0u);

        ans = max(max_sum2 - min_sum2, max_sum1 - min_sum1);
    }
    cout << ans << endl;
    return 0;
}