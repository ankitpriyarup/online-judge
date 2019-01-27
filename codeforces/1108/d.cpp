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
    string s;
    cin >> n >> s;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] == 'B' ? 0 : (s[i] == 'G' ? 1 : 2);
    }

    constexpr int INF = 1e9 + 7;
    vector<vi> dp(n, vi(3, INF)), p(n, vi(3, 0));
    for (int j = 0; j < 3; ++j) {
        dp[0][j] = a[0] != j;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k == j) continue;
                int new_cost = (a[i] != j) + dp[i - 1][k];
                if (new_cost < dp[i][j]) {
                    dp[i][j] = new_cost;
                    p[i][j] = k;
                }
            }
        }
    }

    int j = 0;
    for (int k = 0; k < 3; ++k)
        if (dp[n - 1][k] < dp[n - 1][j])
            j = k;

    cout << dp[n - 1][j] << '\n';
    for (int i = n - 1; i >= 0; --i) {
        s[i] = "BGR"[j];
        j = p[i][j];
    }
    cout << s << '\n';

    return 0;
}
