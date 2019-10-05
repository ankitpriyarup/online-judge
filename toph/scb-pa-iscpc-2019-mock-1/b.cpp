#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e5 + 5;
int bit[MAXN];

int query(int x) {
    int res = 0;
    for (++x; x > 0; x -= (x & -x)) {
        res += bit[x];
    }

    return res;
}

void update(int x, int v) {
    for (++x; x < MAXN; x += (x & -x)) {
        bit[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));
    b.erase(unique(all(b)), end(b));
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(all(b), a[i]) - begin(b);
    }

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        int exp = i;
        int found = query(a[i]);
        ans += (exp - found);
        update(a[i], 1);
    }

    cout << ans << '\n';
    
    return 0;
}
