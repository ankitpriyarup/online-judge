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

    int n, k;
    cin >> n >> k;

    vi a(n), r(n);
    iota(all(a), 0);
    iota(all(r), 0);
    vector<pii> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i].second >> b[i].first;
    }

    sort(all(b));
    for (auto& p : b) {
        int u = p.second;
        int v = u + 1;

        int x = r[u];
        int y = r[v];

        a[x] = v;
        a[y] = u;

        r[u] = y;
        r[v] = x;
    }

    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
