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
    vi coins(n);
    for (auto& coin : coins) {
        cin >> coin;
    }

    constexpr int INF = 1e9 + 7;
    vi dp(x + 1, INF);
    dp[0] = 0;
    for (int coin : coins) {
        for (int i = 0; i + coin <= x; ++i) {
            dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }

    cout << ((dp[x] == INF) ? -1 : dp[x]) << '\n';
    
    return 0;
}
