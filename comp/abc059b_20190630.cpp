#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(123456789012345678901234567890
234567890123456789012345678901
)");
#endif
    string a, b;
    in >> a >> b;
    string {5, '0'};
    if (a.length() > b.length()) b.insert(0, string(a.length() - b.length(), '0'));
    else if (a.length() < b.length()) a.insert(0, string(b.length() - a.length(), '0'));
//    cout << a << endl << b << endl;

    for (int i = 0; i < a.length(); ++i) {
        auto a_i = stoi(a.substr(i, 1));
        auto b_i = stoi(b.substr(i, 1));
        if (a_i > b_i) {
            cout << "GREATER" << endl;
            exit(0);
        } else if (a_i < b_i) {
            cout << "LESS" << endl;
            exit(0);
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}