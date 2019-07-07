// https://beta.atcoder.jp/contests/abc070

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "YES", string no = "NO") { cout << (cond ? yes : no) << endl; }

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    print_yes_no((100 * r + 10 * g + b) % 4 == 0);
    return 0;
}