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
    vector<ll> a(n + 1);
    a[1] = 1;
    a[2] = 1;
    constexpr ll INF = 1e18;
    for (int i = 3; i <= n; ++i) {
        a[i] = min(INF, a[i - 2] + a[i - 1]);
    }
    /*
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    */

    int i = n;
    for (; i - 2 >= 1;) {
        // cout << "k i " << k << " " << i << '\n';
        if (k > a[i - 2]) {
            k -= a[i - 2];
            i -= 1;
        } else {
            i -= 2;
        }
    }

    if (k == 1 and i == 1) {
        cout << 'N';
    } else if (k == 1 and i == 2) {
        cout << 'A';
    } else if (i == 3) {
        cout << "NA"[k - 1];
    } else {
        assert(false);
    }

    return 0;
}
