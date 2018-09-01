// https://beta.atcoder.jp/contests/abc085
// status: [solve]
// tag: [exhaustive_search]

#define SUBMIT

#include <iostream>

using namespace std;


int main() {
    int N, Y;
    cin >> N >> Y;

    Y /= 1000;

    for (int x = 0; x <= N; ++x) {
        for (int y = 0; x + y <= N; ++y) {
            auto z = N - (x + y);
            auto sum = 10 * x + 5 * y + z;
            if (sum == Y) {
                cout << x << " " << y << " " << z << endl;
                exit(0);
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}