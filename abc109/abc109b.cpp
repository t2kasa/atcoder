// https://beta.atcoder.jp/contests/abc109

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(50
)");
#endif
    int N;
    stream >> N;
    string prev;
    set<string> s;
    for (int i = 0; i < N; ++i) {
        string curr;
        stream >> curr;
        if (s.find(curr) != s.end()) {
            cout << "No" << endl;
            exit(0);
        }

        if (i != 0 && prev[prev.length() - 1] != curr[0]) {
            cout << "No" << endl;
            exit(0);
        }
        prev = curr;
        s.insert(curr);
    }
    cout << "Yes" << endl;
    return 0;
}