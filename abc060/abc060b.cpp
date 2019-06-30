#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

const int n_cities = 50;

int road[n_cities];

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(8 8
1 2
3 4
1 5
2 8
3 7
5 2
4 1
6 8
)");
#endif
    int n, m;
    in >> n >> m;

    for (int i = 0; i < n; ++i) road[i] = 0;

    int a_i, b_i;
    for (int i = 0; i < m; ++i) {
        in >> a_i >> b_i;
        road[a_i - 1]++;
        road[b_i - 1]++;
    }

    for (int i = 0; i < n; ++i) cout << road[i] << endl;

    return 0;
}