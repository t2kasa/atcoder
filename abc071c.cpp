// https://beta.atcoder.jp/contests/abc071

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(10
3 3 3 3 4 4 4 5 5 5
)");
#endif
    // (side, count)
    map<int, int> sides;
    int N, A;
    stream >> N;
    for (int i = 0; i < N; ++i) {
        stream >> A;
        sides[A]++;
    }

    int select = 0;
    uint64_t area = 1;
    for (auto it = sides.rbegin(); it != sides.rend(); ++it) {
        if (select == 2) break;
        while (2 <= it->second) {
            area *= it->first;
            it->second -= 2;

            select++;
            if (select == 2) break;
        }
    }
    if (select == 2) cout << area << endl;
    else cout << "0" << endl;
    return 0;
}