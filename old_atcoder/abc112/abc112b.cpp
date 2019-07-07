// https://beta.atcoder.jp/contests/abc112

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> c;
    for (int i = 0; i < N; ++i) {
        int ci, ti;
        cin >> ci >> ti;
        if (ti <= T) c.push_back(ci);
    }

    if (c.empty()) cout << "TLE" << endl;
    else cout << *min_element(c.begin(), c.end()) << endl;
    return 0;
}