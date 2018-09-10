// https://beta.atcoder.jp/contests/abc064

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(9
3200 3200 1600 2000 3200 3200 3200 3200 3200
)");
#endif

    int count8 = 0;
    // (color, count)
    set<int> color_counts;
    int n;
    stream >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        stream >> a;
        a = min(3200, a);
        a /= 400;
        color_counts.insert(a);
        if(a == 8) count8++;
    }

    int ans_min = color_counts.size() - (0 < count8);
    if (ans_min == 0) ans_min = 1;
    int ans_max = color_counts.size() - (0 < count8) + count8;
    cout << ans_min << " " << ans_max << endl;
    return 0;
}