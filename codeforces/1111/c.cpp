#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n, k, a, b;
int p[MAXN];

int q(int x) {
    int lo = 0;
    int hi = k;
    if (p[lo] >= x)
        return 0;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (p[mid] < x)
            lo = mid;
        else
            hi = mid;
    }

    return hi;
}

int q(int l, int r) {
    return q(r) - q(l);
}

ull solve(int l, int r) {
    int sz = r - l;
    if (sz == 1) {
        auto f = equal_range(p, p + k, l);
        if (f.first != p + k and *f.first == l) {
            return 1LL * b * (f.second - f.first);
        } else {
            return a;
        }
    }

    int inside = q(l, r);
    if (inside == 0) {
        return a;
    }

    int h = sz >> 1;
    int m = l + h;
    ull burn = 1ULL * b * inside * sz;
    ull rec = solve(l, m) + solve(m, r);

    return min(burn, rec);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> a >> b;
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
        --p[i];
    }
    sort(p, p + k);

    cout << solve(0, 1 << n) << '\n';
    
    return 0;
}
