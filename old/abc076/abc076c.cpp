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

string S, T;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto program_input = std::string(R"(?tc????
coder
)");
    stringstream stream(program_input);
#endif
    stream >> S >> T;

    int str_length = S.length();
    int key_length = T.length();

    string ans = "~";
    for (int i = 0; i <= str_length - key_length; ++i) {
        bool ok = true;
        for (int j = 0; j < key_length; ++j) {
            if (S[i + j] != '?' && S[i + j] != T[j]) ok = false;
        }

        if (ok) {
            string s2 = S;
            s2.replace(i, T.length(), T);
            for (int j = 0; j < s2.length(); ++j) if (s2[j] == '?') s2[j] = 'a';
            ans = min(ans, s2);
        }
    }

    if (ans == "~") cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;
    return 0;
}