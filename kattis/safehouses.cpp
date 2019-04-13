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
    vector<string> g(n);

    vector<pii> houses, spies;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 'H')
                houses.emplace_back(i, j);
            else if (g[i][j] == 'S')
                spies.emplace_back(i, j);
        }
    }

    int ans = 0;
    for (auto& spy : spies) {
        int cur = 1e9 + 7;
        for (auto& house : houses) {
            int dx = abs(house.first - spy.first);
            int dy = abs(house.second - spy.second);
            cur = min(cur, dx + dy);
        }
        ans = max(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}
