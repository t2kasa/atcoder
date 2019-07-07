#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

const int64_t MAX_R = static_cast<int64_t>(1e9);

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3
4
3
2
)");
#endif
    int n;
    in >> n;
    vector<int> R;
    for (int i = 0; i < n; ++i) {
        int temp;
        in >> temp;
        R.push_back(temp);
    }

    int min_R = R[0];
    int ans = -static_cast<int>(1e10);
    for (int j = 1; j < n; ++j) {
        ans = max(ans, R[j] - min_R);
        min_R = min(min_R, R[j]);
    }
    cout << ans << endl;
    return 0;
}