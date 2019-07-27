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

    int n;
    cin >> n;
    vector<int> p(n), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector<int> seen(n, false);
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0 or !seen[p[i] - 1]) {
            dp[p[i]] = 1;
        } else {
            dp[p[i]] = 1 + dp[p[i] - 1];
        }

        seen[p[i]] = true;
    }

    cout << (n - *max_element(all(dp))) << '\n';

    return 0;
}
