// https://beta.atcoder.jp/contests/abc074
// status: [solve][review]
// tag:

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

const int MAX_F = 3000;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(17 19 22 26 55 2802
)");
#endif
    int A, B, C, D, E, F;
    stream >> A >> B >> C >> D >> E >> F;
    A *= 100; B *= 100;

    set<int> sum_waters;
    set<int> sum_sugars;
    for (int i = 0; i <= MAX_F / A; ++i) {
        for (int j = 0; j <= MAX_F / B; ++j) {
            if (i == 0 && j == 0) continue;
            auto sum = A * i + B * j;
            if (F < sum) continue;
            sum_waters.insert(sum);
        }
    }

    for (int i = 0; i <= MAX_F / C; ++i) {
        for (int j = 0; j <= MAX_F / D; ++j) {
            auto sum = C * i + D * j;
            if (F < sum) continue;
            sum_sugars.insert(sum);
        }
    }

    int best_w = 0;
    int best_s = 0;
    double max_c = -1.0;
    for (auto w : sum_waters) {
        for (auto s : sum_sugars) {
            if (F < w + s) continue;
            if (E * w / 100 < s) continue;
            double c = static_cast<double>(s) / (w + s);
            if (max_c < c) {
                max_c = c;
                best_w = w;
                best_s = s;
            }
        }
    }

    cout << (best_w + best_s) << " " << best_s << endl;
    return 0;
}