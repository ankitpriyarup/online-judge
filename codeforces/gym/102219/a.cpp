#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

char f[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int rot = 0;
    for (char c : s) {
        if (c == 'L') {
            rot += 3;
        } else {
            rot += 1;
        }
        rot &= 3;
    }

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    f['^'] = '>';
    f['>'] = 'v';
    f['v'] = '<';
    f['<'] = '^';
    f['.'] = '.';

    for (int k = 0; k < rot; ++k) {
        vector<string> new_grid(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // (i, j) => (j, n - 1 - i)
                new_grid[j][n - 1 - i] = f[grid[i][j]];
            }
        }

        swap(grid, new_grid);
    }

    for (string& row : grid) {
        cout << row << '\n';
    }
    return 0;
}
