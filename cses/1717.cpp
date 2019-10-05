#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int sum(int a, int b, int mod=MOD) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=MOD) {
    return (1LL * a * b) % mod;
}

constexpr int MAXN = 1e6 + 1;
int D[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // derangements:
    // D(n) = (n - 1)(D(n - 1) + D(n - 2))
    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i <= n; ++i) {
        D[i] = prod(i - 1, sum(D[i - 1], D[i - 2]));
    }

    cout << D[n] << '\n';
    
    return 0;
}
