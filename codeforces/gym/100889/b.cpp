#include <iostream>

using namespace std;

int n;
long long a[100005];

int main() {
    int num_cases;
    cin >> num_cases;

    while (num_cases-- > 0) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int l_ptr = 0;
        long long l_value = a[0];

        int r_ptr = n - 1;
        long long r_value = a[n - 1];

        int merges = 0;
        while (l_ptr < r_ptr) {
            if (l_value == r_value) {
                ++l_ptr;
                --r_ptr;
                l_value = a[l_ptr];
                r_value = a[r_ptr];
            } else if (l_value < r_value) {
                ++l_ptr;
                l_value += a[l_ptr];
                ++merges;
            } else {
                --r_ptr;
                r_value += a[r_ptr];
                ++merges;
            }
        }

        cout << merges << '\n';
    }
    return 0;
}
