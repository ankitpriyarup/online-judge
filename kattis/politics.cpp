#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;

double dp[MAXN];
vector<pii> meetings[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int s, a, b;
        cin >> s >> a >> b;
        meetings[s].emplace_back(a, b);
    }

    for (int i = MAXN - 3; i >= 0; --i) {
        dp[i] = dp[i + 1] - dp[i + 2];

        for (auto& p : meetings[i]) {
            int a, b;
            tie(a, b) = p;
            dp[i] = max(dp[i], 1.0 + (dp[i + a] - dp[min(i + b + 1, MAXN - 1)]) / (b - a + 1.0));
        }

        dp[i] += dp[i + 1];
    }

    cout << fixed << setprecision(12);
    cout << dp[0] - dp[1] << '\n';
    
    return 0;
}
