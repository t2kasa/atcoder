#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(resident register number
)");
#endif
    string a, b, c;
    in >> a >> b >> c;
    cout << static_cast<char>(toupper(a[0])) << static_cast<char>(toupper(b[0])) << static_cast<char>(toupper(c[0]))
         << endl;
    return 0;
}