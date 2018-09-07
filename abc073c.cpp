// https://beta.atcoder.jp/contests/abc073
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(6
12
22
16
22
18
12
)");
#endif
    set<int> A;
    int N;
    stream >> N;
    for (int i = 0; i < N; ++i) {
        int v;
        stream >> v;
        if (A.find(v) == A.end()) A.insert(v);
        else A.erase(v);
    }
    cout << A.size() << endl;
    return 0;
}