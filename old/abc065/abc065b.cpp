// https://beta.atcoder.jp/contests/abc066

#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int a[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int push = 0;
    bool ok = false;
    int curr = 1;
    while (true) {
        if (curr == 2) {
            ok = true;
            break;
        }
        if (visited[curr]) break;
        push++;
        visited[curr] = true;
        curr = a[curr];
    }

    if (ok) cout << push << endl;
    else cout << "-1" << endl;
}