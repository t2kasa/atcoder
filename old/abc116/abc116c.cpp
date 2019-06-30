// https://beta.atcoder.jp/contests/abc116

#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

void print_vector(const vector<int>& a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(8
4 23 75 0 23 96 50 100
)");
#endif
    int n;
    in >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) in >> h[i];

    int ans = 0;
    vector<int> v(n);

    while (true) {
        int left = 0;
        for (int r = 0; r < n; ++r) {
            if (v[r] == h[r]) {
                for (int j = left; j < r; ++j) v[j]++;
                if (left != r) ans++;
                left = r + 1;

//                print_vector(v, n);
            }
        }

        for (int j = left; j < n; ++j) v[j]++;
        if (left != n) {
            ans++;
//            print_vector(v, n);
        }

        bool done = true;
        for (int i = 0; i < n; ++i) {
            if (v[i] != h[i]) done = false;
        }
        if (done) break;
    }

    cout << ans << endl;
    return 0;
}