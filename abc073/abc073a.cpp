// https://beta.atcoder.jp/contests/abc073
// status: [solve]

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N / 10 == 9 || N % 10 == 9) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}