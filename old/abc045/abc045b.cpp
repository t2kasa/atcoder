// https://beta.atcoder.jp/contests/abc045
// status: [solve]

#define SUBMIT
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(aca
accc
ca
)");
#endif

    string S[3];
    stream >> S[0] >> S[1] >> S[2];
    char current = 0;
    while (true) {
        if (S[current].size() == 0) {
            cout << static_cast<char>('A' + current) << endl;
            break;
        }

        char next = S[current][0] - 'a';
        S[current].erase(S[current].begin());
        current = next;
    }
    return 0;
}