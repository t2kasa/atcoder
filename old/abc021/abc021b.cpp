// https://beta.atcoder.jp/contests/abc021
// status: [solve]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using ui64 = uint64_t;
using namespace std;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto input = std::string(R"(20
1 4
12
2 3 5 7 8 9 10 11 12 15 13 14
)");
    stringstream stream(input);
#endif
    int N, K;
    int a, b, v;
    set<int> unique_nodes;
    stream >> N;
    stream >> a >> b;
    unique_nodes.insert(a);
    unique_nodes.insert(b);
    stream >> K;

    bool shortest_possible = true;
    for (int i = 0; i < K; ++i) {
        stream >> v;
        if (unique_nodes.find(v) != unique_nodes.end()) {
            shortest_possible = false;
            break;
        }
        unique_nodes.insert(v);
    }

    if (shortest_possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}