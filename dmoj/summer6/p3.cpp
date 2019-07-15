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
    ll m;
    cin >> m;
    int j;
    cin >> j;

    vector<ll> p(n + 1);
    for (int i = 0; i < j; ++i) {
        int xi, xf, k;
        cin >> xi >> xf >> k;
        p[xi - 1] += k;
        p[xf] -= k;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        p[i + 1] += p[i];

        if (p[i] < m) {
            ++ans;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
