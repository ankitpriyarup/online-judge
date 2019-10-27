#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 5003;
int n, m, p;
int x[MAXN], y[MAXN];
bool used[MAXN];

ll dist(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];

    return 1LL * dx * dx + 1LL * dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 0; i < n + m + p; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<tuple<ll, int, int>> opts;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < n + m; ++j) {
            ll d = dist(i, j);
            opts.emplace_back(d, i, j);
        }
    }

    double ans = 0.0;
    sort(all(opts));
    for (auto& s : opts) {
        ll d;
        int i, j;
        tie(d, i, j) = s;
        if (used[i] or used[j]) continue;
        used[i] = used[j] = true;
        ans += sqrt(d);
    }

    opts.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = n + m; j < n + m + p; ++j) {
            ll d = dist(i, j);
            opts.emplace_back(d, i, j);
        }
    }

    sort(all(opts));
    memset(used, 0, sizeof(used));
    for (auto& s : opts) {
        ll d;
        int i, j;
        tie(d, i, j) = s;
        if (used[i] or used[j]) continue;
        used[i] = used[j] = true;
        ans += sqrt(d);
    }

    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}
