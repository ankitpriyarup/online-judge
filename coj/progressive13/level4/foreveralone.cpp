#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            --x;
            a[i] = a[i - 1] ^ (1LL << (ll)x);
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            int l, r;
            cin >> l >> r;
            ll res = a[r] ^ a[l - 1];
            cout << __builtin_popcountll(res) << '\n';
        }
    }

    return 0;
}
