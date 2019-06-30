// https://beta.atcoder.jp/contests/abc062
// status: [review]
// tag: [priority_queue]

#define SUBMIT

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

const int MAX_N = 100000;
i64 a[MAX_N * 3];
i64 left_sum[MAX_N + 1], right_sum[MAX_N + 1];
int N, N2, N3;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(3
8 2 2 7 4 6 5 3 8
)");
#endif
    stream >> N;
    N2 = 2 * N, N3 = 3 * N;
    for (int i = 0; i < N3; ++i) stream >> a[i];

    i64 ls = 0, rs = 0;
    priority_queue<i64, vector<i64>, greater<>> left_pq;
    priority_queue<i64> right_pq;
    for (int i = 0; i < N; ++i) {
        ls += a[i];
        left_pq.push(a[i]);

        rs += a[(N3 - 1) - i];
        right_pq.push(a[(N3 - 1) - i]);
    }

    left_sum[0] = ls;
    right_sum[N] = rs;
    for (int k = 0; k < N; ++k) {
        left_sum[1 + k] += left_sum[k];
        if (left_pq.top() < a[N + k]) {
            left_sum[1 + k] += a[N + k] - left_pq.top();
            left_pq.pop();
            left_pq.push(a[N + k]);
        }

        right_sum[(N - 1) - k] = right_sum[N - k];
        if (a[(N2 - 1) - k] < right_pq.top()) {
            right_sum[(N - 1) - k] += a[(N2 - 1) - k] - right_pq.top();
            right_pq.pop();
            right_pq.push(a[(N2 - 1) - k]);
        }
    }

    // NOTE: ansの最小値をINT_MINにするとWA
    i64 ans =  numeric_limits<i64>::min();
    for (int i = 0; i <= N; ++i) ans = max(ans, left_sum[i] - right_sum[i]);

    cout << ans << endl;
    return 0;
}