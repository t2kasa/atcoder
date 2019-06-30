#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(77 42 36
)");
#endif
    int A, B, C;
    in >> A >> B >> C;
    int k = 1;
    while (k * A < A * B) {
        if ((k * A) % B == C) {
            cout << "YES" << endl;
            exit(0);
        }
        k++;
    }
    cout << "NO" << endl;
    return 0;
}