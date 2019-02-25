#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
vector<pii> tree[MAXN];
ll dp[2][MAXN];

ll dp0(int u, int par = -1);
ll dp1(int u, int par = -1);

// dp[0][u] = ans for subtree of u if u is root of some path
ll dp0(int u, int par) {
    ll& res = dp[0][u];
    if (res != -1)
        return res;

    res = 0;
    vector<ll> bests;
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == par) continue;
        res += dp0(v, u);
        bests.push_back(w + dp1(v, u) - dp0(v, u));
    }

    sort(all(bests));
    reverse(all(bests));
    if (!bests.empty()) {
        ll nr = res;
        if (bests.size() >= 2) {
            nr = max(nr, res + bests[0] + bests[1]);
        }
        nr = max(nr, res + bests[0]);

        res = nr;
    }

    return res;
}

// dp[1][u] = ans for subtree of u if path starts from above u
ll dp1(int u, int par) {
    ll& res = dp[1][u];
    if (res != -1)
        return res;

    res = 0;
    ll best = -1e18;
    for (auto& e : tree[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == par) continue;

        res += dp0(v, u);
        best = max(best, w + dp1(v, u) - dp0(v, u));
    }

    res += max(0LL, best);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    memset(dp, -1, sizeof(dp));
    ll ans = max(dp0(0), dp1(0));
    /*
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            cout << dp[k][i] << ' ';
        }
        cout << '\n';
    }
    */
    cout << ans << '\n';

    return 0;
}
