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
int selection_sort(vector<T>& a) {
    int swap_count = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        auto min_j = i;
        for (int j = i; j < a.size(); ++j) {
            if (a[j] < a[min_j]) min_j = j;
        }

        swap(a[i], a[min_j]);
        if (i != min_j) swap_count++;
    }
    return swap_count;
}

int main() {
#ifdef SUBMIT
    auto& in = cin;
#else
    stringstream in(R"(6
5 6 4 2 1 3
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

    auto swap_count = selection_sort(a);
    print_array(a);
    cout << swap_count << endl;
    return 0;
}