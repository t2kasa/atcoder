#define SUBMIT

#include <iostream>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
    int K;
    cin >> K;
    auto a = K / 2;
    auto ans = a * (K - a);
    cout << ans << endl;
    return 0;
}