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
    for (auto& x : a) {
        cin >> x;
    }
    sort(all(a));
    int med = a[n / 2];
    ll ans = 0;
    for (int x : a) {
        ans += abs(x - med);
    }
    cout << ans << '\n';
    return 0;
}
