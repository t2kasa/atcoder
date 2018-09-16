// https://beta.atcoder.jp/contests/abc062

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Yes", string no = "No") { cout << (cond ? yes : no) << endl; }

int main() {
    int a[] = {1, 3, 5, 7, 8, 10, 12};
    int b[] = {4, 6, 9, 11};
    int c[] = {2};
    int id[12 + 1];
    for (auto i : a) id[i] = 0;
    for (auto i : b) id[i] = 1;
    for (auto i : c) id[i] = 2;

    int x, y;
    cin >> x >> y;
    print_yes_no(id[x] == id[y]);
    return 0;
}