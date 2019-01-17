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
    vector<vi> a(n, vi(n, 0));
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            a[i][j] = 1 + ((i + j) % (n - 1));
    for (int i = 0; i < n - 1; ++i) {
        a[n - 1][i] = a[i][n - 1] = a[i][i];
        a[i][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
