#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int SIGMA = 60;
constexpr ll INF = 1.5e17;
char c[SIGMA];
ll pows[SIGMA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        ll m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        pows[0] = 1;
        for (int i = 1; i < SIGMA; ++i) {
            if (pows[i - 1] >= INF / m) {
                pows[i] = INF;
            } else {
                pows[i] = 1LL * pows[i - 1] * m;
            }
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            ll k;
            cin >> k;

            int len = 0;
            while (k >= pows[len]) {
                k -= pows[len];
                ++len;
            }

            string res;
            for (int i = 0; i < len; ++i) {
                int idx = k / pows[len - i - 1];
                res.push_back(c[idx]);
                k %= pows[len - i - 1];
            }

            cout << res << '\n';
        }
    }
    
    return 0;
}
