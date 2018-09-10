// https://beta.atcoder.jp/contests/abc070

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Yes", string no = "No") { cout << (cond ? yes : no) << endl; }

int main() {
    string s;
    cin >> s;
    print_yes_no(s[0] == s[2]);
    return 0;
}