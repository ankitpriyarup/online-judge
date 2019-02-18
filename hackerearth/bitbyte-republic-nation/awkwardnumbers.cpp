#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        g = gcd(g, a[i]);
    }

    // dp[i][j] = can you make digit i with first j stones
    // dp[i][j] = dp[i - 1][j] | dp[i - 1][(j - k * w[j]) % m] over all k
    // ax + by + cz = d
    // by bezout's lemma, possible iff gcd(a,b,c) | d
    // take gcd of all of these
    // oh but has to be positive >_<
    // also need to check if divides any of d, m + d, 2m + d, ...
    // i guess code the O(nk) solution and pray?
    // bitsets would help a lot...
    // each value is a mask
    // or all the shifted masks together somehow
    // so obviously 1 makes everything
    // 2 makes everything if m % 2 == 1 else only evens
    // gcd of all a[i] and m????
    g = gcd(g, m);
    cout << (m / g) << '\n';
    for (int x = 0; x < m; x += g) {
        cout << x << " ";
    }

    return 0;
}
