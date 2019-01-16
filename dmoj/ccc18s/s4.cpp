#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int SQRT = 1 << 15;
map<int, ll> memo;
int dp_p = 1;
ll dp[SQRT];

ll solve(int n) {
    if (n <= dp_p) {
        return dp[n];
    }

    auto it = memo.find(n);
    if (it != end(memo))
        return it->second;

    int w = 1;
    ll res = 0LL;
    for (; w * w <= n; ++w) {
        int lo = (n + w + 1) / (w + 1);
        int hi = n / w;
        if (lo > hi)
            break;

        res += (hi - lo + 1) * solve(w);
    }

    for (int k = 2; k <= n; ++k) {
        int v = n / k;
        if (v < w)
            break;
        res += solve(v);
    }

    return memo[n] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    for (int i = 2; i < SQRT; ++i) {
        dp[i] = solve(i);
        dp_p = i;
    }

    cout << solve(n);

    return 0;
}
