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

    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i - 1] <= x) {
            ans = i + 1;
        } else {
            break;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
