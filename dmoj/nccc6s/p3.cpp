#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

int gcd(int a, int b) {
    if (a == 0 and b == 0)
        return 1;
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ++n; ++m;
    int w;
    cin >> w;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vi> wind(n, vi(m, 0));
    while (w-- > 0) {
        int x, y;
        cin >> x >> y;
        wind[x][y] = true;
    }

    using state = tuple<int, int, int, int>;
    // constexpr int VB = 30;
    queue<state> q;
    q.emplace(sx, sy, 0, 0);

    vi ax = {0, 1, 0, -1, 0};
    vi ay = {0, 0, 1, 0, -1};

    auto p_in_bounds = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    };

    auto v_in_bounds = [&](int vx, int vy) {
        return -n <= vx and vx < n and -m <= vy and vy < m;
    };

    auto no_wind = [&](int x, int y, int gx, int gy) {
        if (wind[gx][gy])
            return false;

        int dx = gx - x;
        int dy = gy - y;
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        while (x != gx or y != gy) {
            if (wind[x][y]) 
                return false;
            x += dx;
            y += dy;
        }

        return true;
    };

    vector<vector<vector<vector<bool>>>> seen(n, 
           vector<vector<vector<bool>>>(m,
                  vector<vector<bool>>(n + n,
                         vector<bool>(m + m, false))));

    seen[sx][sy][n][m] = true;
    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            int x, y, vx, vy;
            tie(x, y, vx, vy) = q.front();
            q.pop();

            for (int d = 0; d < 5; ++d) {
                int nvx = vx + ax[d];
                int nvy = vy + ay[d];
                int nx = x + nvx;
                int ny = y + nvy;

                if (p_in_bounds(nx, ny) and v_in_bounds(nvx, nvy) and no_wind(x, y, nx, ny)) {
                    if (nx == ex and ny == ey and nvx == 0 and nvy == 0) {
                        cout << (lvl + 1) << '\n';
                        return 0;
                    }

                    if (!seen[nx][ny][n + nvx][m + nvy]) {
                        seen[nx][ny][n + nvx][m + nvy] = true;
                        q.emplace(nx, ny, nvx, nvy);
                    }
                }
            }
        }

        ++lvl;
    }

    cout << -1 << '\n';
    return 0;
}
