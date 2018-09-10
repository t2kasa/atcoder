// https://beta.atcoder.jp/contests/abc064

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(6
)))())
)");
#endif
    int n;
    stream >> n;

    stack<string> s;
    int left_count = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        stream >> c;
        if (c == ')') {
            string a = ")";

            string t;
            while (!s.empty()) {
                t = s.top(); s.pop();
                a.insert(0, t);
                if (t == "(") break;
            }

            if (t == "(") {
                s.push(a);
                left_count--;
            }
            else s.push("(" + a);
        }
        else {
            s.push("(");
            left_count++;
        }
    }

    vector<string> ans_rev;
    while (!s.empty()) {
        ans_rev.push_back(s.top()); s.pop();
    }
    string ans = accumulate(ans_rev.rbegin(), ans_rev.rend(), string());
    for (int i = 0; i < left_count; ++i) ans += ")";
    cout << ans << endl;
    return 0;
}