#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int p;

int sum(int a, int b, int mod=p) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=p) {
    return (1LL * a * b) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> p >> k;

    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int x2 = prod(x, x);
        int x4 = prod(x2, x2);
        int v = sum(x4, p - prod(k, x));
        ++freq[v];
    }

    ll ans = 0;
    for (auto f : freq) {
        int v = f.second;
        ans += 1LL * v * (v - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
