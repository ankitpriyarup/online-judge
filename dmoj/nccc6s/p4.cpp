#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int a, b, c, d;
ll solve(const vector<ll>& f, int x) {
    if (x <= 0)
        return 1;
    if (x < (int)f.size())
        return f[x];

    return solve(f, (x / a) - b) + solve(f, (x / c) - d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> a >> b >> c >> d >> q;
    assert(a > 0 and c > 0);

    constexpr int MAXN = 10000007;
    vector<ll> f(MAXN);
    f[0] = 1;
    for (int x = 1; x < MAXN; ++x) {
        f[x] = f[max(0, (x / a) - b)] + f[max(0, (x / c) - d)];
    }

    while (q-- > 0) {
        int x;
        cin >> x;
        cout << solve(f, x) << '\n';
    }
    
    return 0;
}
