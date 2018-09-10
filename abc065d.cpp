// https://beta.atcoder.jp/contests/abc065
// status: [review][study]
// tag: [最小全域木][minimum_spanning_tree]

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define SUBMIT
//#define DEBUG

struct node {
    int x, y, id;
};

struct edge {
    int u, v, d;

    bool operator<(const edge& other) const { return d < other.d; }
};

node a[200010];
edge g[300010];
int n, m, fa[200010];

int cmpx(const node& lhs, const node& rhs) { return lhs.x < rhs.x; }
int cmpy(const node& lhs, const node& rhs) { return lhs.y < rhs.y; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(6
8 3
4 9
12 19
18 1
13 5
7 6
)");
#endif
    stream >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        stream >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a + 1, a + n + 1, cmpx);
    for (int i = 1; i < n; ++i) g[++m] = edge {a[i].id, a[i + 1].id, a[i + 1].x - a[i].x};
    sort(a + 1, a + n + 1, cmpy);
    for (int i = 1; i < n; ++i) g[++m] = edge {a[i].id, a[i + 1].id, a[i + 1].y - a[i].y};

    int ans = 0;
    sort(g + 1, g + m + 1);
    for (int i = 1; i <= m; ++i) {
        if (find(g[i].u) != find(g[i].v))
        {
            ans += g[i].d;
            fa[fa[g[i].u]] = fa[g[i].v];
        }
    }
    cout << ans << endl;
    return 0;
}