// https://beta.atcoder.jp/contests/abc115

//#define SUBMIT

#include <bits/stdc++.h>
using namespace std;


int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(7 4
1 1
2 1
3 1
4 6
4 5
4 5
4 5
)");
#endif
    int n, n_choices;
    in >> n >> n_choices;
    vector<vector<int>> d(n);
    int t_i, d_i;
    for (int i = 0; i < n; ++i) {
        in >> t_i >> d_i;
        d[t_i - 1].push_back(d_i);
    }
    for (int i = 0; i < n; ++i) {
        sort(d[i].begin(), d[i].end(), greater<>());
    }

    uint64_t prev_deli_sum = 0;
    uint64_t prev_total = 0;
    set<long> selected_sushi_kinds;
    for (int u = 0; u < n_choices; ++u) {
        vector<uint64_t> curr_deii_sum_points;
        vector<uint64_t> curr_totals;

        for (int i = 0; i < n; ++i) {
            if (d[i].size() == 0) {
                curr_deii_sum_points.push_back(0);
                curr_totals.push_back(0);
                continue;
            }

            uint64_t curr_deli_sum = prev_deli_sum + d[i][0];
            auto n_kinds = selected_sushi_kinds.count(i) ? selected_sushi_kinds.size() : selected_sushi_kinds.size() + 1;
            curr_deii_sum_points.push_back(curr_deli_sum);
            curr_totals.push_back(curr_deli_sum + n_kinds * n_kinds);
        }

        auto max_index = distance(curr_totals.begin(), max_element(curr_totals.begin(), curr_totals.end()));
        d[max_index].erase(d[max_index].begin());
        selected_sushi_kinds.insert(max_index);
        prev_deli_sum = curr_deii_sum_points[max_index];
        prev_total = curr_totals[max_index];

        cout << max_index << " " << prev_deli_sum << " " << prev_total << endl;
    }

    cout << prev_total;
    return 0;
}