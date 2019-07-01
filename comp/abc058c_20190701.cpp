#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3
cbaa
daacc
acacac
)");
#endif
    int n;
    in >> n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) in >> S[i];

    vector<int> whole_counter(26);
    for (int& c : whole_counter) c = 100;

    for (int j = 0; j < n; ++j) {
        vector<int> counter(26);
        for (int k = 0; k < S[j].length(); ++k) {
            counter[S[j][k] - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            whole_counter[i] = min(whole_counter[i], counter[i]);
        }
    }

//    for (auto c : whole_counter) cout << c << " ";
//    cout << endl;

    for (int i = 0; i < 26; ++i) {
        cout << string(whole_counter[i], 'a' + i);
    }
    cout << endl;
    return 0;
}