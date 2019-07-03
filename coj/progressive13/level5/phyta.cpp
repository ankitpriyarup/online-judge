#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 2003;
int n;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= a[i];
            ll cur = a[i];
            ll best = cur;
            for (int j = i + 1; j < n; ++j) {
                cur = max(cur + a[j], (ll)a[j]);
                best = max(best, cur);
                res ^= best;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
