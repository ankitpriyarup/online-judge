#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
int dp[MAXN];

int solve(int x) {
    if (x < 10) {
        return x > 0;
    }

    if (dp[x]) {
        return dp[x];
    }

    int res = 1e9;
    int chop = x;
    while (chop) {
        int d = chop % 10;
        if (d) {
            res = min(res, 1 + solve(x - d));
        }
        chop /= 10;
    }

    return dp[x] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << solve(n);
    
    return 0;
}
