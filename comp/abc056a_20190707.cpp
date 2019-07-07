#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(D D
)");
#endif
    string a, b;
    in >> a >> b;
    if ((a == "H" && b == "H") || (a == "D" && b == "D")) cout << "H" << endl;
    else cout << "D" <<endl;
    return 0;
}