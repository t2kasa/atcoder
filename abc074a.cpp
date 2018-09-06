// https://beta.atcoder.jp/contests/abc074
// status: [solve]
// tag:

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    auto ans = N * N - A;
    cout << ans << endl;
    return 0;
}