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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    int m;
    cin >> m;
    int ans = -1;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (r >= sum) {
            ans = max(sum, l);
            break;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
