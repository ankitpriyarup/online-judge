#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1000000007;

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

int solve(vi& a) {
    sort(all(a));

    int n = a.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        if (v < 0)
            v += MOD;
        res = sum(res, prod(i, v));
        res = sum(res, prod(n - 1 - i, MOD - v));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vi a(n);
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int res = sum(solve(a), solve(b));

    cout << res << '\n';
    
    return 0;
}
