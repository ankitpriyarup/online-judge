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
    for (auto& row : grid) {
        cin >> row;
    }

    int ans = 1;
    for (int j = 0; j < m; ++j) {
        bool all_space = true;
        for (int i = 0; i < n; ++i) {
            all_space &= grid[i][j] == '_';
        }

        ans += all_space;
    }

    cout << ans << '\n';
    
    return 0;
}
