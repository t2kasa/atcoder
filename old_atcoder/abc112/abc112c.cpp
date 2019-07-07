// https://beta.atcoder.jp/contests/abc112
// status: [review]

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(5
100 100 0
2 3 5
2 1 5
1 2 5
3 2 5
)");
#endif
    int n;
    in >> n;

    vector<int> x, y, h;
    for (int i = 0; i < n; ++i) {
        int xi, yi, hi;
        in >> xi >> yi >> hi;
        x.push_back(xi);
        y.push_back(yi);
        h.push_back(hi);
    }

    auto non_zero_index = std::distance(h.begin(), find_if(h.begin(), h.end(), [](int hi) { return hi != 0; }));
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int h_est = h[non_zero_index] + abs(cx - x[non_zero_index]) + abs(cy - y[non_zero_index]);
            bool ok = true;
            for (int i = 0; i < x.size(); ++i) {
                if (h[i] == 0) {
                    if (abs(cx - x[i]) + abs(cy - y[i]) < h_est) ok = false;
                }
                else if (h_est != h[i] + abs(cx - x[i]) + abs(cy - y[i])) ok = false;
            }

            if (ok) {
                cout << cx << " " << cy << " " << h_est << endl;
                exit(0);
            }
        }
    }
    return 0;
}