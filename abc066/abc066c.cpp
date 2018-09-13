// https://beta.atcoder.jp/contests/abc066

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    deque<int> q;
    int n;
    cin >> n;
    bool even_is_front = n % 2 == 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (even_is_front) {
            if (i % 2 == 0) q.push_front(a);
            else q.push_back(a);
        }
        else {
            if (i % 2 == 0) q.push_back(a);
            else q.push_front(a);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << q.front();
        q.pop_front();
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}