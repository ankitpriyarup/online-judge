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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int r = 0;
    int ans = 1;
    for (int l = 0; l < n; ++l) {
        while (r + 1 < n and a[r + 1] - a[l] <= k)
            ++r;
        ans = max(ans, r - l + 1);
    }
    
    cout << ans << '\n';
    return 0;
}
