#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char moves[] = "DLUR";

bool works(const vector<string>& grid, const string& s, int x, int y, int d, int p) {
    if (p == s.size()) return true;
    if (s[p] != grid[x][y]) return false;

    int nx = x + dx[d];
    int ny = y + dy[d];
    while (nx < 0) nx += n;
    while (ny < 0) ny += m;
    nx %= n;
    ny %= m;

    return works(grid, s, nx, ny, d, p + 1);
}

void solve() {
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        string s;
        cin >> s;

        bool found = false;
        for (int i = 0; !found and i < n; ++i) {
            for (int j = 0; !found and j < m; ++j) {
                if (grid[i][j] == s[0]) {
                    for (int d = 0; d < 4; ++d) {
                        if (works(grid, s, i, j, d, 0)) {
                            found = true;

                            cout << moves[d] << " " << (i + 1) << " " << (j + 1) << " " << s << '\n';
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cout << "Word search puzzle #" << tc++ << ":\n";
        solve();
        cout << '\n';
    }
    
    return 0;
}
