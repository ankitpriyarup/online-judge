#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct BIT {
    int n;
    vi data;
    BIT(int n): n(n), data(n + 1, 0) {}

    int query(int x) const {
        int res = 0;
        for (++x; x; x -= (x & -x)) {
            res += data[x];
        }

        return res;
    }

    int query(int l, int r) const {
        return query(r) - query(l - 1);
    }

    void update(int x, int v) {
        for (++x; x < data.size(); x += (x & -x)) {
            data[x] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vi> l(n, vi(m, 0));
    vector<vi> u(n, vi(m, 0));
    vector<vi> r(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            l[i][j] = u[i][j] = r[i][j] = grid[i][j] =='z';
            if (j > 0 and l[i][j]) {
                l[i][j] += l[i][j - 1];
            }
            if (i > 0 and j + 1 < m and u[i][j]) {
                u[i][j] += u[i - 1][j + 1];
            }
        }
        for (int j = m - 2; j >= 0; --j) {
            if (r[i][j]) {
                r[i][j] += r[i][j + 1];
            }
        }
    }

    /**
     * zz
     * zz
     *
     * l
     * 12
     * 12
     *
     * r
     * 21
     * 21
     *
     * u
     * 11
     * 21
     */

    ll ans = 0LL;
    for (int diag = 0; diag <= n + m - 2; ++diag) {
        BIT bit(n + m);
        vector<vi> events(n + m);
        for (int i = 0; i <= diag; ++i) {
            for (int x : events[i]) {
                bit.update(x, -1);
            }

            int j = diag - i;
            if (!(0 <= i and i < n and 0 <= j and j < m) or grid[i][j] != 'z') {
                continue;
            }

            int range = min(r[i][j], u[i][j]);
            bit.update(i, 1);
            ans += bit.query(i - range + 1, i);
            int death = i + l[i][j];
            if (death < events.size()) {
                events[death].push_back(i);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
