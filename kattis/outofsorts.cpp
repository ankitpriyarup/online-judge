#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
int v[MAXN], lo[MAXN], hi[MAXN];

void dfs(int l, int r, int ql, int qr) {
    if (l > r) return;

    int mid = (l + r) / 2;
    lo[mid] = ql;
    hi[mid] = qr;

    dfs(l, mid - 1, ql, min(qr, v[mid]) - 1);
    dfs(mid + 1, r, max(ql, v[mid]) + 1, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;

    v[0] = x0;
    for (int i = 1; i <= n; ++i) {
        v[i] = (1LL * a * v[i - 1] + c) % m;
    }

    dfs(1, n, 0, m);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << v[i] << ' ' << lo[i] << ' ' << hi[i] << '\n';
        if (lo[i] <= v[i] and v[i] <= hi[i]) {
            ++ans;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
