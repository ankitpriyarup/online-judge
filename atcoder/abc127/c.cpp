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
    int x = 1;
    int y = n;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        x = max(l, x);
        y = min(r, y);
    }

    int ans = max(0, y - x + 1);
    cout << ans;
    
    return 0;
}
