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

    int n, w;
    cin >> n >> w;

    // what is the max value for weight i
    vector<ll> dp(w + 1, 0);

    for (int i = 0; i < n; ++i) {
        ll wi, vi;
        cin >> wi >> vi;
        for (int j = w - wi; j >= 0; --j) {
            dp[j + wi] = max(dp[j + wi], vi + dp[j]);
        }
    }

    cout << dp[w] << '\n';
    
    return 0;
}
