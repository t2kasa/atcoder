#define SUBMIT

#include <bits/stdc++.h>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    auto s = std::string(R"(31 -41 -59 26
)");
    stringstream stream(s);
#endif
    int x1, y1, x2, y2;
    stream >> x1 >> y1 >> x2 >> y2;

    auto dx12 = x2 - x1;
    auto dy12 = y2 - y1;

    auto x3 = x2 - dy12;
    auto y3 = y2 + dx12;

    auto x4 = x3 - dx12;
    auto y4 = y3 - dy12;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}