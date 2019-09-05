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

    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vi dp(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] >= a[i + 1]) {
            dp[i] = 1 + dp[i + 1];
        }
    }

    cout << *max_element(all(dp)) << '\n';
    
    return 0;
}
