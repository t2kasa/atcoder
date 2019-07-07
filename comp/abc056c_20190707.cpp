#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

const int64_t MAX_X = static_cast<int64_t>(1e9);

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6
)");
#endif
    int64_t X;
    in >> X;
    int64_t ans = 0;
    int64_t sum = 0;
    for (int i = 1; i <= MAX_X; ++i) {
        sum += i;
        if (X <= sum) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}