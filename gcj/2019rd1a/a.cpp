#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 21;
int r, c;
int rows[MAXN];
bool vis[MAXN][MAXN];
vector<pii> stk;
bool pos = false;

void dfs(int x, int y) {
    if (pos) {
        return;
    }

    stk.emplace_back(x, y);
    vis[x][y] = true;
    if (stk.size() == r * c) {
        pos = true;
        return;
    }

    for (int i = 0; i < r; ++i) {
        if (i == x || rows[i] == c) continue;
        for (int j = 0; j < c; ++j) {
            if (j == y || i + j == x + y || i - j == x - y || vis[i][j]) continue;
            vis[i][j] = true;
            ++rows[i];
            dfs(i, j);

            if (pos) return;
            vis[i][j] = false;
            --rows[i];
        }
    }

    stk.pop_back();
}

// row is - 2
vector<pii> dp[3][21];
void solve(int _r, int _c) {
    // solve and leave in dp
    r = _r;
    c = _c;
    pos = false;
    stk.clear();
    memset(vis, 0, sizeof(vis));
    memset(rows, 0, sizeof(rows));
    dfs(0, 0);
    dp[_r - 2][_c] = stk;
}

void validate(const vector<pii>& ans, int n, int m) {
    vector<vector<int>> seen(n, vi(m, 0));
    assert(ans.size() == n * m);
    for (int i = 0; i < n * m; ++i) {
        int x = ans[i].first;
        int y = ans[i].second;
        assert(!seen[x][y]);
        seen[x][y] = true;
        if (i) {
            int ox = ans[i - 1].first;
            int oy = ans[i - 1].second;
            assert(!(x == ox or y == oy or x + y == ox + oy or x - y == ox - oy));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // precompute the answers for every size 2 and 3
    // use those to build up the final answer?
    for (int y = 5; y <= 20; ++y) {
        solve(2, y);
    }
    for (int y = 4; y <= 7; ++y) {
        solve(3, y);
    }
    for (int y = 8; y <= 20; ++y) {
        int cur = y;
        int offset = 0;
        while (cur >= 8) {
            for (auto& p : dp[1][4]) {
                dp[1][y].emplace_back(p.first, p.second + offset);
            }
            cur -= 4;
            offset += 4;
        }
        for (auto& p : dp[1][cur]) {
            dp[1][y].emplace_back(p.first, p.second + offset);
        }
    }
    solve(4, 4);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cin >> r >> c;
        bool flip = false;
        if (r > c) {
            flip = true;
            swap(r, c);
        }

        if ((r == 2 and c < 5) or (r == 3 and c < 4)) {
            cout << "Case #" << tc++ << ": " << "IMPOSSIBLE\n";
            continue;
        }

        cout << "Case #" << tc++ << ": " << "POSSIBLE\n";
        vector<pii> ans;

        if (r == 4 and c == 4) {
            ans = dp[2][4];
        } else {
            int cur = r;
            int offset = 0;
            while (cur > 3) {
                for (auto& p : dp[0][c]) {
                    ans.emplace_back(p.first + offset, p.second);
                }
                cur -= 2;
                offset += 2;
            }
            for (auto& p : dp[cur - 2][c]) {
                ans.emplace_back(p.first + offset, p.second);
            }
        }

        // validate(ans, r, c);

        for (auto& p : ans) {
            if (flip) {
                cout << (p.second + 1)  << ' ' << (p.first + 1) << '\n';
            } else {
                cout << (p.first + 1)  << ' ' << (p.second + 1) << '\n';
            }
        }
    }

    return 0;
}
