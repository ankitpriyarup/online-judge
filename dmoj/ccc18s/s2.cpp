#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int goal = 1e9 + 7;
    for (int i = 0; i < n; i += n - 1) {
        for (int j = 0; j < n; j += n - 1) {
            goal = min(goal, a[i][j]);
        }
    }

    while (a[0][0] != goal) {
        // rotate by 90 degrees: transpose and then reverse each row
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(a[i][j], a[j][i]);
            }
        }
        for (int i = 0; i < n; ++i)
            reverse(all(a[i]));
    }
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
