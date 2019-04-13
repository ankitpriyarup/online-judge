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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    if (a[0] != a[n - 1]) {
        cout << (n - 1) << '\n';
    } else {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[0]) {
                ans = max(ans, i);
                ans = max(ans, n - 1 - i);
            }
        }

        cout << ans  << '\n';
    }
    
    return 0;
}
