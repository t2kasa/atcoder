// https://beta.atcoder.jp/contests/abc067

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Possible", string no = "Impossible") { cout << (cond ? yes : no) << endl; }

int main() {
    int a, b;
    cin >> a >> b;
    print_yes_no(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    return 0;
}