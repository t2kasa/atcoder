#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    for (int i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            auto half = a / 2;
            a = half;
            b += half;
        }
        else {
            auto half = b / 2;
            b = half;
            a += half;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}