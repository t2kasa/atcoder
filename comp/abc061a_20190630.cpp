#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6 5 4
)");
#endif
    int a, b, c;
    in >> a >> b >> c;
    auto ans = (a <= c && c <= b) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}