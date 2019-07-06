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

    vector<pii> stk = {{0, 0}};
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        while (stk.back().first >= x) {
            int h = stk.back().first;
            stk.pop_back();
            int l = stk.back().second;
            ans = max(ans, 1LL * (i - l - 1) * h);
        }

        stk.emplace_back(x, i);
    }

    while (stk.back().first != 0) {
        int h = stk.back().first;
        stk.pop_back();

        ans = max(ans, 1LL * (n - stk.back().second) * h);
    }

    cout << ans << '\n';

    return 0;
}
