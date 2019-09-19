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

    string ans(32, 'z');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m;) {
            if (grid[i][j] == '#') {
                ++j;
            } else {
                int len = 0;
                while (j + len < m and grid[i][j + len] != '#')
                    ++len;
                if (len > 1) {
                    ans = min(ans, grid[i].substr(j, len));
                }

                j += len;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n;) {
            if (grid[i][j] == '#') {
                ++i;
            } else {
                int len = 0;
                while (i + len < n and grid[i + len][j] != '#') {
                    ++len;
                }

                if (len > 1) {
                    string t;
                    for (int k = 0; k < len; ++k) {
                        t.push_back(grid[i + k][j]);
                    }

                    ans = min(ans, t);
                }

                i += len;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
