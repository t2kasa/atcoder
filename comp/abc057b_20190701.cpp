#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

struct point {
    int64_t x;
    int64_t y;
};

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(5 5
-100000000 -100000000
-100000000 100000000
100000000 -100000000
100000000 100000000
0 0
0 0
100000000 100000000
100000000 -100000000
-100000000 100000000
-100000000 -100000000
)");
#endif
    int N, M;
    in >> N >> M;
    vector<point> students(N);
    vector<point> checkpoints(M);

    for (int i = 0; i < N; ++i) {
        int64_t a, b;
        in >> a >> b;
        students[i].x = a;
        students[i].y = b;
    }

    for (int i = 0; i < M; ++i) {
        int64_t c, d;
        in >> c >> d;
        checkpoints[i].x = c;
        checkpoints[i].y = d;
    }

    for (int i = 0; i < N; ++i) {
        int64_t min_dist = static_cast<int64_t>(1e16);
        int min_index = -1;
        for (int j = 0; j < M; ++j) {
            int64_t dist = abs(students[i].x - checkpoints[j].x) + abs(students[i].y - checkpoints[j].y);
            if (dist < min_dist) {
                min_dist = dist;
                min_index = j;
            }
        }

        cout << min_index + 1 << endl;
    }

    return 0;
}