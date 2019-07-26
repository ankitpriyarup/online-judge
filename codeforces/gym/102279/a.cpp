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

    ll INF = 3000000000;
    int n;
    vector<int> v(3);
    cin >> n;
    ++n;
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    vector<int> owner(n, -1);
    vector<int> p(3, 0);

    ll ans = -1;
    for (int i = 0; ans == -1 and i < n; ++i) {
        for (int k = 0; ans == -1 and k < 3; ++k) {
            p[k] += v[k];
            if (p[k] >= n)
                p[k] -= n;

            // cout << (3 * i + k + 1) << ' ' << p[k] << '\n';
            if (p[k] == 0) continue;
            else if (owner[p[k]] == -1) {
                owner[p[k]] = k;
            } else if (owner[p[k]] != k) {
                ans = 3 * i + k + 1;
                break;
            }
        }
    }

    if (ans == -1)
        ans = INF;
    cout << ans << '\n';
    
    return 0;
}
