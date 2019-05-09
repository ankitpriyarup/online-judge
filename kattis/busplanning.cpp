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

    int n, k, c;
    cin >> n >> k >> c;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }
    sort(all(names));
    vector<vi> bad(n, vi(n, 0));
    for (int i = 0; i < k; ++i) {
        string a, b;
        cin >> a >> b;
        int u = lower_bound(all(names), a) - begin(names);
        int v = lower_bound(all(names), b) - begin(names);
        bad[u][v] = bad[v][u] = true;
    }

    vi valid(1 << n, 0);
    for (int m = 1; m < (1 << n); ++m) {
        if (__builtin_popcount(m) > c) continue;

        valid[m] = true;
        for (int i = 0; i < n; ++i) {
            if ((m & (1 << i)) == 0) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if ((m & (1 << j)) == 0) {
                    continue;
                }

                valid[m] &= !bad[i][j];
            }
        }
    }

    int INF = 20;
    vi dp(1 << n, INF);
    dp[0] = 0;
    vi jmp(1 << n, 0);
    for (int m = 1; m < (1 << n); ++m) {
        for (int s = m; s; s = (s - 1) & m) {
            if (!valid[s]) continue;
            if (dp[m ^ s] + 1 < dp[m]) {
                dp[m] = dp[m ^ s] + 1;
                jmp[m] = s;
            }
        }
    }

    int cur = (1 << n) - 1;
    cout << dp[cur] << '\n';
    while (cur) {
        int s = jmp[cur];
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                cout << names[i] << ' ';
            }
        }
        cout << '\n';

        cur ^= s;
    }
    
    return 0;
}
