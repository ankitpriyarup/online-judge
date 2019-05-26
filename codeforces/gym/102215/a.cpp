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
    }

    int r = n;
    vi ans(n), follow(n + 1, n);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 0) {
            r = min(r, follow[-a[i]]);
        } else {
            follow[a[i]] = i;
        }

        ans[i] = r - i;
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    
    return 0;
}
