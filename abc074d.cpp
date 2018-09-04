// https://beta.atcoder.jp/contests/abc074
// status: [solve][review]
// tag: [ワーシャルフロイド]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>
using namespace std;
using ui64 = uint64_t;

const int MAX_N = 300;
ui64 A[MAX_N][MAX_N];
ui64 d[MAX_N][MAX_N];
int N;

void floyd() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(3
0 1 3
1 0 2
3 2 0
)");
#endif
    stream >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            stream >> A[y][x];
            d[y][x] = A[y][x];
        }
    }

    floyd();
    bool exist = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (d[i][j] != A[i][j]) exist = false;
        }
    }

    if (!exist) {
        cout << "-1" << endl;
        exit(0);
    }

    ui64 ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool avoid = false;
            for (int k = 0; k < N; ++k) {
                if (i == k || j == k) continue;
                if (d[i][j] == d[i][k] + d[k][j]) avoid = true;
            }
            if (!avoid) {
                ans += d[i][j];
            }
        }
    }
    cout << ans << endl;

 #ifdef DEBUG
    cout << "floyd" << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << d[y][x] << " ";
        }
        cout << endl;
    }

    cout << "input" << endl;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << A[y][x] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}