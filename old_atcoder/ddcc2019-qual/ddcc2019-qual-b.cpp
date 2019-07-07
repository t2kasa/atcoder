// https://beta.atcoder.jp/contests/ddcc2019-qual

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        auto half = n / 2;
        auto sum = 0;
        for (int i = 1; i <= half - 1; ++i) {
            sum += i;
        }
        auto ans = sum * 4;
        cout << ans << endl;
    }
    else {
        auto half = (n + 1) / 2;
        auto sum = 0;
        for (int i = 1; i <= half - 1; ++i) {
            sum += i;
        }
        auto ans = sum * 4 - 3 - (half - 1 - 1) * 4;
        cout << ans << endl;
    }
    return 0;
}