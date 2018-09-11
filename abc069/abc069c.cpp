// https://beta.atcoder.jp/contests/abc069

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

void print_yes_no(bool cond, string yes = "Yes", string no = "No") { cout << (cond ? yes : no) << endl; }

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(6
2 7 1 8 2 8
)");
#endif
    int mul4 = 0, mul2 = 0, mul1 = 0;
    int n;
    stream >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        stream >> a;
        if (a % 4 == 0) mul4++;
        else if(a % 2 == 0) mul2++;
        else mul1++;
    }

    mul1 += mul2 % 2;
    print_yes_no(mul1 <= mul4 + 1);
    return 0;
}