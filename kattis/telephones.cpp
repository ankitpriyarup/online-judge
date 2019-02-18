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
    while (cin >> n >> m) {
        if (n == 0) break;

        vector<pii> calls(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y >> calls[i].first >> calls[i].second;
        }

        while (m-- > 0) {
            int u, v;
            cin >> u >> v;
            int ans = 0;
            for (auto& p : calls) {
                if (p.first >= u + v or u >= p.first + p.second)
                    continue;
                ++ans;
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}
