#include <iostream>

using namespace std;

int n;
long long a[10004];
long long b[10004];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int ans = (b[0] <= a[0]) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            long long has = a[i] - a[i - 1];
            long long wants = b[i];
            if (wants <= has)
                ++ans;
        }

        cout << ans << '\n';
    }
    return 0;
}
