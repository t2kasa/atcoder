#define SUBMIT

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
vector<T> divisor(T x) {
    vector<T> d;
    for (T i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            d.emplace_back(i);
            if (i * i != x) d.push_back(x / i);
        }
    }
    sort(d.begin(), d.end());
    return move(d);
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(3 14
)");
#endif
    unsigned long long n, m;
    in >> n >> m;

    decltype(m) ans = 1;
    auto d = divisor(m);
    for (auto di : d) {
        if (di * n <= m) ans = max(ans, di);
    }
    cout << ans << endl;
    return 0;
}