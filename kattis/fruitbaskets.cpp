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

    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a)
        cin >> x;
    ll ans = 0LL;
    for (auto& x : a) {
        ans += (1LL << (n - 1LL)) * x;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] < 200)
            ans -= a[i];

        for (int j = i + 1; j < n; ++j) {
            if (a[i] + a[j] < 200)
                ans -= a[i] + a[j];

            for (int k = j + 1; k < n; ++k) {
                if (a[i] + a[j] + a[k] < 200) {
                    ans -= a[i] + a[j] + a[k];
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
