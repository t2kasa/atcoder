// https://beta.atcoder.jp/contests/abc111

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_max(map<int, int>& m) {
    auto max_v = -1, max_count = -1;
    for (auto p : m) {
        if (max_count < p.second) {
            max_v = p.first;
            max_count = p.second;
        }
    }

    return {max_v, max_count};
}

int compute_cost(int n, pair<int, int>& even_max_p, pair<int, int>& odd_max_p) {
    auto half = n / 2;
    return (half - even_max_p.second) + (half - odd_max_p.second);
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(4
1 1 1 1
apple
)");
#endif
    map<int, int> even_count, odd_count;

    // dummy
    even_count[0] = 0, odd_count[0] = 0;

    int n;
    in >> n;
    int v;
    for (int i = 0; i < n; ++i) {
        in >> v;
        if (i % 2 == 0) even_count[v]++;
        else odd_count[v]++;
    }

    int ans = 0;
    auto even_max_p = find_max(even_count);
    auto odd_max_p = find_max(odd_count);

    if (even_max_p.first != odd_max_p.first) ans = compute_cost(n, even_max_p, odd_max_p);
    else {
        even_count.erase(even_max_p.first);
        auto next_even_max_p = find_max(even_count);
        auto even_erase_cost = compute_cost(n, next_even_max_p, odd_max_p);

        odd_count.erase(odd_max_p.first);
        auto next_odd_max_p = find_max(odd_count);
        auto odd_erase_cost = compute_cost(n, even_max_p, next_odd_max_p);

        ans = min(even_erase_cost, odd_erase_cost);
    }

    cout << ans << endl;
    return 0;
}