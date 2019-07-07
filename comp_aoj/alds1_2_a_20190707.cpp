#define SUBMIT

#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_array(const vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (0 < i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

template <typename T>
int bubble_sort(vector<T>& a) {
    int swap_count = 0;
    bool swap_flag = true;
    while (swap_flag) {
        swap_flag = false;
        for (int j = a.size() - 1; j >= 1; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                swap_flag = true;
                swap_count++;
            }
        }
    }

    return swap_count;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6
5 2 4 6 1 3
)");
#endif
    int n;
    in >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int temp;
        in >> temp;
        a.push_back(temp);
    }

    auto swap_count = bubble_sort(a);
    print_array(a);
    cout << swap_count << endl;
    return 0;
}