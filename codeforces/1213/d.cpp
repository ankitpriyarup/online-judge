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

    constexpr int MAXN = 2e5 + 5;
    int n, k;
    cin >> n >> k;
    vector<vi> costs(MAXN);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int moves = 0;
        while (x > 0) {
            costs[x].push_back(moves);
            ++moves;
            x /= 2;
        }
    }

    int ans = 1e9 + 7;
    for (int i = 0; i < MAXN; ++i) {
        if (costs[i].size() < k) continue;
        sort(begin(costs[i]), end(costs[i]));
        int val = 0;
        for (int j = 0; j < k; ++j) {
            val += costs[i][j];
        }

        ans = min(ans, val);
    }

    cout << ans << '\n';
    
    return 0;
}
