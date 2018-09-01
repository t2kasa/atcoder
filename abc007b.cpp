// https://beta.atcoder.jp/contests/abc007
// status: [solve]

#define SUBMIT

#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
    string A;
    cin >> A;
    if (A == "a") {
        cout << "-1" << endl;
        exit(0);
    }

    if (A.length() == 1) {
        cout << static_cast<char>(A[0] - 1) << endl;
        exit(0);
    }

    cout << A.substr(0, A.length() - 1) << endl;
    return 0;
}