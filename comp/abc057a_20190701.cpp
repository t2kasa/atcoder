#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(19 0
)");
#endif
    int A, B;
    in >> A >> B;
    auto ans = (A + B) % 24;
    cout << ans << endl;
    return 0;
}