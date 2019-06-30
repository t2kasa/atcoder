// https://beta.atcoder.jp/contests/abc114

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

bool can_divide(int x) {
    auto s = to_string(x);

    if (s.find('3') == string::npos) return false;
    if (s.find('5') == string::npos) return false;
    if (s.find('7') == string::npos) return false;

    set<char> chars;
    for (auto c : s) chars.insert(c);
    return chars.size() == 3;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(999999999
)");
#endif
    string s;
    in >> s;

    queue<int> q;
    q.push(0);

    auto ans = 0;
    int n = stoi(s);
    for (int i = 0; i < s.length(); ++i) {
        queue<int> next_q;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            if (v <= n && can_divide(v)) {
//                cout << v << endl;
                ans++;
            }

            next_q.push(v * 10 + 3);
            next_q.push(v * 10 + 5);
            next_q.push(v * 10 + 7);
        }
        q = next_q;
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v <= n && can_divide(v)) {
//            cout << v << endl;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}