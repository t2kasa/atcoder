// https://beta.atcoder.jp/contests/arc004
// status: [solve]
// tag:

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;


class point2d {
public:
    point2d() : point2d(0, 0) {}

    point2d(double x, double y) : x_(x), y_(y) {}

    double x() const noexcept { return x_; }

    double y() const noexcept { return y_; }

private:
    double x_;
    double y_;
};

double compute_distance(const point2d& p1, const point2d& p2) {
    auto squared_distance = pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2);
    return sqrt(squared_distance);
}

size_t N;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(3
1 1
2 4
4 3
)");

    stringstream stream(s);
#endif
    stream >> N;
    vector<point2d> p;

    double x, y;
    for (int i = 0; i < N; ++i) {
        stream >> x >> y;
        p.emplace_back(x, y);
    }

    double max_distance = numeric_limits<double>::min();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            auto d = compute_distance(p[i], p[j]);
            max_distance = max(max_distance, d);
        }
    }

    cout << setprecision(7) << max_distance << endl;
    return 0;
}