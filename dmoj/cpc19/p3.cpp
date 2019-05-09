#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int parse(const string& s) {
    int res = 0;
    for (char c : s) {
        res <<= 1;
        res += (c == '1');
    }

    return res;
}

int brute(int n, int a, int b) {
    vi dp(1 << n, -1);
    dp[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int m = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if ((m & (1 << i)) == 0) {
                int new_mask = m | (1 << i);
                if (dp[new_mask] == -1) {
                    dp[new_mask] = dp[m] + 1;
                    q.push(new_mask);
                }
            } else {
                for (int rem = 0b111; rem <= m; rem <<= 1) {
                    if ((rem & m) == rem) {
                        int new_mask = m ^ rem;
                        if (dp[new_mask] == -1) {
                            dp[new_mask] = dp[m] + 1;
                            q.push(new_mask);
                        }
                    }
                }

                for (int rem = 0b1111; rem <= m; rem <<= 1) {
                    if ((rem & m) == rem) {
                        int new_mask = m ^ rem;
                        if (dp[new_mask] == -1) {
                            dp[new_mask] = dp[m] + 1;
                            q.push(new_mask);
                        }
                    }
                }
            }
        }
    }

    return dp[b];
}

int solve(int n, const string& a, const string& b) {
    constexpr int INF = 1e9 + 7;
    vi dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == b[i]) {
            dp[i] = dp[i + 1];
        }
        if (a[i] == '0' and b[i] == '1') {
            dp[i] = min(dp[i], 1 + dp[i + 1]);
        }
        for (int j = 3; j <= 4 and i + j <= n; ++j) {
            int cur_cost = 0;
            for (int k = i; k < i + j; ++k) {
                if (a[k] == '0') {
                    ++cur_cost;
                }
                if (b[k] == '1') {
                    ++cur_cost;
                }
            }

            dp[i] = min(dp[i], cur_cost + 1 + dp[i + j]);
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    */

    int ans = (dp[0] == INF ? -1 : dp[0]);
    return ans;
}

int solve(int n, int s, int t) {
    string a(n, '0');
    string b(n, '0');
    for (int i = 0; i < n; ++i) {
        if (s & (1 << i))
            a[n - i - 1] = '1';

        if (t & (1 << i))
            b[n - i - 1] = '1';
    }

    return solve(n, a, b);
}

int brute(int n, const string& a, const string& b) {
    return brute(n, parse(a), parse(b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // int res = brute(n, a, b);
    int ans = solve(n, a, b);
    cout << ans << '\n';

    // cout << ans << '\n';
    // cout << "RES: " << res << '\n';
    // assert(ans == res);
    /*
    while (1) {
        int x = rand() % (1 << 10);
        int y = rand() % (1 << 10);
        cout << x << " " << y << '\n';
        assert(brute(14, x, y) == solve(14, x, y));
    }
    */

    return 0;
}
