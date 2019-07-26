#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 2002;
int n;
int v[MAXN];
int hop_one[MAXN], hop_two[MAXN];
int dp[2][MAXN];

int score(int a, int w) {
    // minimum number of doubles needed to clear the first i slots
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;

    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < n; ++i) {
        while (p1 < n and v[p1] < v[i] + w)
            ++p1;
        while (p2 < n and v[p2] < v[i] + w + w)
            ++p2;

        hop_one[i] = p1;
        hop_two[i] = p2;
    }

    for (int j = 0; j <= a; ++j) {
        int k = j % 2;
        for (int i = 0; i < n; ++i) {
            // place_single
            if (j < a) {
                // int idx = lower_bound(all(v), v[i] + w) - begin(v);
                int idx = hop_one[i];
                dp[k ^ 1][idx] = min(dp[k ^ 1][idx], dp[k][i]);
            }

            // place double
            {
                // int idx = lower_bound(all(v), v[i] + w + w) - begin(v);
                int idx = hop_two[i];
                dp[k][idx] = min(dp[k][idx], 1 + dp[k][i]);
            }
        }
    }

    int ans = 1e9 + 9;
    for (int j = 0; j <= a; ++j)
        ans = min(ans, min(dp[0][n], dp[1][n]));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v, v + n);

    int lo = 0;
    int hi = v[n - 1];
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (score(a, mid) <= b) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';
    
    return 0;
}

