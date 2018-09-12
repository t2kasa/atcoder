// https://beta.atcoder.jp/contests/atc001
// status: [solve][review]
// tag: [union_find]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

class disjoint_set {
public:
    disjoint_set() = default;

    explicit disjoint_set(size_t size) : rank_(size), parent_(size) {
        for (int i = 0; i < size; ++i) make_set(i);
    }

    bool same(int x, int y) {
        return find_set(x) == find_set(y);
    }

    void unite(int x, int y) {
        link(find_set(x), find_set(y));
    }

private:
    void make_set(int x) {
        parent_[x] = x;
        rank_[x] = 0;
    }

    void link(int x, int y) {
        if (rank_[y] < rank_[x]) parent_[y] = x;
        else {
            parent_[x] = y;
            if (rank_[x] == rank_[y]) rank_[y]++;
        }
    }

    int find_set(int x) {
        if (x != parent_[x]) parent_[x] = find_set(parent_[x]);
        return parent_[x];
    }

private:
    // tree height
    vector<int> rank_;
    // x is root when x == parent_[x]
    vector<int> parent_;
};

size_t N, Q;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(8 9
0 1 2
0 3 2
1 1 3
1 1 4
0 2 4
1 4 1
0 4 2
0 0 0
1 0 0
)");

    stringstream stream(s);
#endif
    stream >> N >> Q;
    disjoint_set ds(N);

    int P, A, B;
    for (int q = 0; q < Q; ++q) {
        stream >> P >> A >> B;

        if (P == 0) ds.unite(A, B);
        else if (P == 1) {
            if (ds.same(A, B)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}