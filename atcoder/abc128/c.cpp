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
    vi masks(n, 0);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            --x;
            masks[x] |= (1 << i);
        }
    }

    int state = 0;
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        state |= (1 << i) * p;
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cur = state;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur ^= masks[i];
            }
        }

        // cout << mask << " " << cur << '\n';

        if (cur == 0) {
            ++ans;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
