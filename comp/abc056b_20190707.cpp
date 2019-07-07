#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(5 10 1
)");
#endif
    int W, a, b;
    in >> W >> a >> b;

    int ans;
    if (a <= b) {
        ans = (b <= a + W) ? 0 : b - (a + W);
    } else {
        ans = (a <= b + W) ? 0 : a - (b + W);
    }
    cout << ans << endl;
    return 0;
}