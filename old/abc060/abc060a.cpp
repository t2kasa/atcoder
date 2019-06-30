#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(aaaaaaaaab aaaaaaaaaa aaaaaaaaab
)");
#endif
    string a, b, c;
    in >> a >> b >> c;
    if (a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}