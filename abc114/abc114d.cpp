// https://beta.atcoder.jp/contests/abc114

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i != 0) continue;
        int n = 0;
        while (x % i == 0) { n++; x /= i; }
        factors.emplace_back(i, n);
    }
    if (x != 1) factors.emplace_back(x, 1);
    return move(factors);
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(100
)");
#endif
    // <factor, n_factors>
    map<int, int> factor_count;

    uint64_t x;
    in >> x;

    if (x == 1) {
        cout << 0 << endl;
        exit(0);
    }

    for (int i = 2; i <= x; ++i) {
        auto v = factorize(i);
        for (auto p : v) factor_count[p.first] += p.second;
    }

    queue<int> q;
    q.push(1);
    for (auto e : factor_count) {
        queue<int> next_q;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            auto n_factors = e.second + 1;
            if (75 <= n_factors) next_q.push(v * 75);
            if (25 <= n_factors) next_q.push(v * 25);
            if (15 <= n_factors) next_q.push(v * 15);
            if (5 <= n_factors) next_q.push(v * 5);
            if (3 <= n_factors) next_q.push(v * 3);
            next_q.push(v * 1);
        }
        q = next_q;
    }

    auto ans = 0;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v == 75) ans++;
    }
    cout << ans << endl;
    return 0;
}