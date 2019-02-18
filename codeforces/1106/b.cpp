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
    vi a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b) {
        return c[a] < c[b];
    });
    int p = 0;

    while (m-- > 0) {
        int t, d;
        cin >> t >> d;
        --t;
        int take = min(d, a[t]);
        ll cost = 1LL * take * c[t];
        a[t] -= take;
        d -= take;
        while (d) {
            while (p < n and a[idx[p]] == 0)
                ++p;

            if (p >= n) {
                cost = 0;
                break;
            }

            take = min(d, a[idx[p]]);
            cost += 1LL * take * c[idx[p]];
            a[idx[p]] -= take;
            d -= take;
        }

        cout << cost << '\n';
    }
    
    return 0;
}
