#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3 2 1
)");
#endif
    int a, b, c;
    in >> a >> b >> c;
    auto ans = (b - a == c - b) ? "YES" : "NO";
    cout << ans << endl;
    return 0;
}