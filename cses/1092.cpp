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
    ll sum = 1LL * n * (n + 1) / 2;
    ll goal = sum / 2;
    if (2 * goal != sum) {
        cout << "NO\n";
        return 0;
    }

    vi ans;
    for (int i = n; goal > 0 and i >= 1; --i) {
        ll k = min(goal, (ll) i);
        goal -= k;
        ans.push_back((int)k);
    }

    sort(all(ans));
    int p = 0;
    vi ans2;
    for (int i = 1; i <= n; ++i) {
        while (ans[p] < i) ++p;
        if (p == ans.size() or ans[p] > i) {
            ans2.push_back(i);
        }
    }

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    cout << ans2.size() << '\n';
    for (int y : ans2) {
        cout << y << ' ';
    }
    cout << '\n';

    return 0;
}
