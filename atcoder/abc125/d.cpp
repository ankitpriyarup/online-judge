#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
int a[MAXN];
bool hit[2][MAXN];
ll dp[2][MAXN];

ll solve(int k, int idx) {
    if (hit[k][idx])
        return dp[k][idx];

    if (idx == n - 1) {
        return k ? -a[idx] : a[idx];
    }

    // don't push
    ll no_push = (k ? -1 : 1) * a[idx] + solve(0, idx + 1);
    ll push = (k ? 1 : -1) * a[idx] + solve(1, idx + 1);
    hit[k][idx] = true;
    return dp[k][idx] = max(no_push, push);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(0, 0) << '\n';
    
    return 0;
}
