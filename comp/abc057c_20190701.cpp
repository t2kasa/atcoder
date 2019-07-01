#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

template <typename T>
size_t count_n_digits(T x) {
    string str = to_string(x);
    return str.length();
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(9876543210
)");
#endif
    int64_t N;
    in >> N;

    auto ans = count_n_digits(N);
    for (int64_t A = 1; A * A <= N; ++A) {
        if (N % A != 0) continue;
        const int64_t B = N / A;
        ans = min(ans, max(count_n_digits(A), count_n_digits(B)));
    }

    cout << ans << endl;
    return 0;
}