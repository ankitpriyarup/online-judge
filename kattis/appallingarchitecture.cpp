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

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    ll sum = 0LL;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                 sum += 2 * j + 1;
                 ++total;
            }
        }
    }

    // center is sum / total
    int l = 0;
    int r = m - 1;
    while (grid[n - 1][l] == '.')
        ++l;
    while (grid[n - 1][r] == '.')
        --r;

    if (total * 2 * l <= sum and sum < total * 2 * (r + 1)) {
        cout << "balanced\n";
    } else if (sum < total * 2 * l) {
        cout << "left\n";
    } else {
        cout << "right\n";
    }
    
    return 0;
}
