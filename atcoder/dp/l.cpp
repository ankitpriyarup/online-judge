#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<vector<ll>>& dp, const vector<ll>& a, int i, int j) {
    if (i == j)
        return a[i];
    ll& res = dp[i][j];
    if (res != -1)
        return res;
    res = max(a[i] - solve(dp, a, i + 1, j), a[j] - solve(dp, a, i, j - 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << solve(dp, a, 0, n - 1);
    
    return 0;
}
