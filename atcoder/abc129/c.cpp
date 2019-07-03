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

    vi a(n + 1, 0);
    vi b(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        b[x] = 1;
    }

    constexpr int MOD = 1e9 + 7;
    a[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i]) continue;
        for (int j = 1; j <= 2; ++j) {
            if (i + j <= n) {
                a[i + j] += a[i];
                a[i + j] %= MOD;
            }
        }
    }

    cout << a[n] << '\n';
    
    return 0;
}
