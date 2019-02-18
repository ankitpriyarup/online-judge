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

    int n, m, k;
    cin >> n >> m >> k;
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vi a;
    for (int i = 1; i < n; ++i) {
        int v = b[i] - b[i - 1] - 1;
        a.push_back(v);
    }
    sort(all(a));

    --k;
    ll ans = b.back() - b[0] + 1;
    while (k-- > 0) {
        ans -= a.back();
        a.pop_back();
    }

    cout << ans << '\n';
    
    return 0;
}
