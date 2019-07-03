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

    int T;
    cin >> T;
    while (T-- > 0) {
        int m;
        cin >> m;
        vector<char> v(m);
        for (int i = 0; i < m; ++i) {
            cin >> v[i];
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            string s;
            cin >> s;

            int n = s.size();

            vector<ll> pows = {1};
            ll ans = 0;
            for (int len = 0; len < n; ++len) {
                ans += pows[len];
                pows.push_back(pows[len] * m);
            }

            for (int i = 0; i < n; ++i) {
                int k = 0;
                while (v[k] != s[i])
                    ++k;
                ans += 1LL * k * pows[n - i - 1];
            }

            cout << ans << '\n';
        }
    }
    
    return 0;
}
