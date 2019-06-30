// https://beta.atcoder.jp/contests/abc115

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

const int MAX_LEVEL = 50;
uint64_t n_layers[MAX_LEVEL + 1];
uint64_t n_patties[MAX_LEVEL + 1];

void init() {
    n_layers[0] = 1;
    n_patties[0] = 1;
    for (int i = 1; i <= MAX_LEVEL; ++i) {
        n_layers[i] = 2 * n_layers[i - 1] + 3;
        n_patties[i] = 2 * n_patties[i - 1] + 1;
    }
}

uint64_t solve(uint64_t n, uint64_t x) {
    uint64_t ans = 0;
    while (true) {
        if (n == 0) {
            ans++;
            break;
        }
        // left bun
        if (x == 1) break;
        x--;


        // left n - 1
        // dig n - 1 level
        if (x <= n_layers[n - 1]) {
            n--;
            continue;
        }
        x -= n_layers[n - 1];
        ans += n_patties[n - 1];

        // center patty
        ans += 1;
        if (x == 1) break;
        x--;

        // right n - 1
        if (x <= n_layers[n - 1]) {
            n--;
            continue;
        }

        x -= n_layers[n - 1];
        ans += n_patties[n - 1];

        if (x == 1) break;
        cout << "error!";
        exit(1);
    }

    return ans;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(50 4321098765432109
)");
#endif
    init();

    uint64_t n, x;
    in >> n >> x;

    auto ans = solve(n, x);

    cout << ans << endl;
    return 0;
}