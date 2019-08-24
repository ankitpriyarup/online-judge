#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 9;
constexpr int MAXB = 2 * MAXN + 1;

int n, m;
int dp[MAXN][MAXN][1 << MAXB];
string grid[MAXN];
bool vis[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool possible() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            bool can_stamp = grid[i][j] == '#';
            for (int d = 0; d < 4; ++d) {
                can_stamp &= grid[i + dx[d]][j + dy[d]] == '#';
            }

            if (can_stamp) {
                vis[i][j] = true;
                for (int d = 0; d < 4; ++d) {
                    vis[i + dx[d]][j + dy[d]] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' and !vis[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool no_stamp() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#')
                return false;
        }
    }

    return true;
}

inline int get_bit(const int mask, const int k) {
    return (mask >> k) & 1;
}

int solve(int x, int y, int mask) {
    // bitset<19> bs(mask);
    // cout << x << ' ' << y << ' ' << bs << '\n';
    if (x >= n) {
        return 0;
    }
    int& res = dp[x][y][mask];
    if (res != -1)
        return res;
    res = 1e9 + 7;

    int sz = 2 * m + 1;
    if (x + 2 < n and 0 < y and y + 1 < m and grid[x][y] == '#' and grid[x + 1][y - 1] == '#' and grid[x + 1][y] == '#' and grid[x + 1][y + 1] == '#' and grid[x + 2][y] == '#') {
        int new_mask = mask;
        new_mask &= ~(1 << (sz - 1));
        new_mask &= ~(1 << (sz - m - 0));
        new_mask &= ~(1 << (sz - m - 1));
        new_mask &= ~(1 << (sz - m - 2));
        new_mask &= ~1;
        new_mask <<= 1;

        int nx = x;
        int ny = y + 1;
        if (ny == m) {
            nx++;
            ny = 0;
        }

        if (nx + 2 < n) {
            new_mask |= grid[nx + 2][ny] == '#';
        }

        res = min(res, 1 + solve(nx, ny, new_mask));
    }

    if (!get_bit(mask, sz - 1)) {
        int new_mask = mask << 1;
        int nx = x;
        int ny = y + 1;
        if (ny == m) {
            nx++;
            ny = 0;
        }

        if (nx + 2 < n) {
            new_mask |= grid[nx + 2][ny] == '#';
        }

        res = min(res, solve(nx, ny, new_mask));
    }

    return res;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    if (no_stamp()) {
        cout << 0 << '\n';
        return;
    }

    if (!possible()) {
        cout << "impossible\n";
        return;
    }

    int mask = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            mask <<= 1;
            mask |= (grid[i][j] == '#');
        }
    }

    mask <<= 1;
    mask |= (grid[2][0] == '#');

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, mask) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cout << "Image #" << tc++ << ": ";
        solve();
        cout << '\n';
    }
    
    return 0;
}
