#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int uf[MAXN];
ll lo[MAXN], hi[MAXN];

int find(int x) {
    return uf[x] = (x == uf[x] ? x : find(uf[x]));
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return 0;

    lo[xr] = min(lo[xr], lo[yr]);
    hi[xr] = max(hi[xr], hi[yr]);
    uf[yr] = xr;

    return 1;
}

ll get_base(int x) {
    int xr = find(x);
    return hi[xr] - lo[xr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        uf[i] = i;
    }

    sort(all(s));
    s.erase(unique(all(s)), end(s));
    n = s.size();

    for (int i = 0; i < n; ++i) {
        uf[i] = i;
        lo[i] = s[i];
        hi[i] = s[i];
    }

    vector<pair<ll, int>> merges;
    for (int i = 1; i < n; ++i) {
        ll dist = s[i] - s[i - 1];
        merges.emplace_back(dist, i);
    }

    sort(all(merges));

    int q;
    cin >> q;
    vector<pair<ll, int>> queries;
    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        queries.emplace_back(r - l, i);
    }

    sort(all(queries));
    vector<ll> ans(q);
    int p = 0;
    int tot = n;
    ll base = 0LL;
    for (auto& query : queries) {
        ll len; int idx;
        tie(len, idx) = query;

        while (p < merges.size() and merges[p].first <= len) {
            --tot;

            int i = merges[p].second;
            int j = i - 1;

            base -= get_base(i);
            base -= get_base(j);
            merge(i, j);
            base += get_base(i);

            ++p;
        }

        ans[idx] = 1LL * tot * (len + 1) + base;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
