#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int64_t compute_min_diff(int64_t h, int64_t w) {
    int64_t ans = h * w;
    for (int64_t y = 1; y < h; ++y) {
        // horizontal line case
        int64_t h_line = y + (h - y) / 2;
        int64_t s1 = y * w;
        int64_t s2 = (h_line - y) * w;
        int64_t s3 = (h - h_line) * w;
        ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));

        // vertical line case
        int64_t v_line = w / 2;
        int64_t s4 = (h - y) * v_line;
        int64_t s5 = (h - y) * (w - v_line);
        ans = min(ans, max({s1, s4, s5}) - min({s1, s4, s5}));
    }

    return ans;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(100000 100000
)");
#endif
    int h, w;
    in >> h >> w;

    auto ans = min(compute_min_diff(h, w), compute_min_diff(w, h));
    cout << ans << endl;
    return 0;
}