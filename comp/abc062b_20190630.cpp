#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(1 1
z
)");
#endif
    int h, w;
    in >> h >> w;

    string head_tail(w + 2, '#');
    cout << head_tail << endl;
    for (int i = 0; i < h; ++i) {
        string s;
        in >> s;
        cout << "#" << s << "#" << endl;
    }
    cout << head_tail << endl;
    return 0;
}