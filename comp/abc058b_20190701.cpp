#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(atcoderbeginnercontest
atcoderregularcontest
)");
#endif
    string O, E;
    in >> O >> E;
    for (int i = 0; i < E.length(); ++i) {
        cout << O[i] << E[i];
    }
    if (O.length() > E.length()) cout << O[O.length() - 1];
    cout << endl;

    return 0;
}