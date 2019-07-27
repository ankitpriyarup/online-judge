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

    ll n;
    cin >> n;
    vector<ll> ans;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0 and ans[i - 1] == ans[i])
            continue;

        cout << ans[i] - 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
