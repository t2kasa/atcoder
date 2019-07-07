// https://beta.atcoder.jp/contests/abc076
// status: [review][solve]

#define SUBMIT
//#define DEBUG

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>
#include <numeric>
#include <limits>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 100;
int N;
double t[MAX_N];
double v[MAX_N];

struct constraint { double t_left, t_right, v; };
constraint constraints[MAX_N];

double compute_max_v(const constraint& c, double t) {
    if (t <= c.t_left) return c.v + c.t_left - t;
    else if (c.t_right <= t) return c.v + t - c.t_right;
    else return c.v;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(10
64 55 27 35 76 119 7 18 49 100
29 19 31 39 27 48 41 87 55 70
)");
    stringstream stream(program_input);
#endif
    stream >> N;
    for (int i = 0; i < N; ++i) stream >> t[i];
    for (int i = 0; i < N; ++i) stream >> v[i];

    for (int i = 0; i < N; ++i) {
        if (i == 0) constraints[i].t_left = 0.0;
        else constraints[i].t_left = t[i - 1] + constraints[i - 1].t_left;

        if (i == 0) constraints[i].t_right = t[i];
        else constraints[i].t_right = constraints[i].t_left + t[i];

        constraints[i].v = v[i];
    }

    // 制約を2つ追加
    constraints[N].t_left = 0.0;
    constraints[N].t_right = 0.0;
    constraints[N].v = 0.0;
    constraints[N + 1].t_left = constraints[N - 1].t_right;
    constraints[N + 1].t_right = constraints[N - 1].t_right;
    constraints[N + 1].v = 0.0;

    double ans = 0.0;
    for (double curr_t = 0.5; curr_t <= constraints[N - 1].t_right; curr_t += 0.5) {
        double min_max_v_left = numeric_limits<double>::max();
        double min_max_v_right = numeric_limits<double>::max();
        for (int i = 0; i < N + 2; ++i) {
            min_max_v_left = min(min_max_v_left, compute_max_v(constraints[i], curr_t - 0.5));
            min_max_v_right = min(min_max_v_right, compute_max_v(constraints[i], curr_t));
        }

        ans += (min_max_v_left + min_max_v_right) * 0.5 / 2.0;
    }

    cout << fixed << setprecision(18) << ans << endl;
    return 0;
}