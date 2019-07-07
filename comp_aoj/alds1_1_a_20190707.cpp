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
void insertion_sort(vector<T>& a) {
    for (int i = 1; i < a.size(); ++i) {
        auto key = a[i];
        int j = i - 1;
        while (0 <= j && key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        print_array(a);
    }
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

    print_array(a);
    insertion_sort(a);
    return 0;
}