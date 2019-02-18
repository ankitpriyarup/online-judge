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
    vi a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    sort(all(a));
    a.erase(unique(all(a)), end(a));

    // can skip n - 1 gaps
    vi b;
    for (int i = 1; i < a.size(); ++i) {
        b.push_back(a[i] - a[i - 1]);
    }
    sort(all(b));
    for (int i = 0; !b.empty() and i < n - 1; ++i)
        b.pop_back();
    ll ans = 0LL;
    for (int x : b)
        ans += x;

    cout << ans << '\n';

    
    return 0;
}
