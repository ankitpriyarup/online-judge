#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 505;
int dp[MAXN][MAXN];

int solve(int a, int b) {
    if (a == b) {
        return 0;
    }
    if (a > b) swap(a, b);
    if (dp[a][b])
        return dp[a][b];
    int res = 1e9;
    for (int l = 1; l < a; ++l) {
        res = min(res, 1 + solve(l, b) + solve(a - l, b));
    }
    for (int l = 1; l < b; ++l) {
        res = min(res, 1 + solve(a, l) + solve(a, b - l));
    }

    return dp[a][b] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';

    return 0;
}
