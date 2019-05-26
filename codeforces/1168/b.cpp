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

    string s;
    cin >> s;

    // count the number of ones without triples.
    // Only have to consider masks of size < 10
    vector<vi> triple_free(10);
    for (int k = 1; k < 10; ++k) {
        for (int m = 0; m < (1 << k); ++m) {
            bool trip = false;
            for (int x = 0; !trip and x < k; ++x) {
                for (int d = 1; !trip and x + d + d < k; ++d) {
                    bool a = (m & (1 << x)) > 0;
                    bool b = (m & (1 << (x + d))) > 0;
                    bool c = (m & (1 << (x + d + d))) > 0;
                    if (a == b and b == c) {
                        trip = true;
                        break;
                    }
                }
            }

            if (!trip) {
                // cout << k << " " << m << '\n';
                triple_free[k].push_back(m);
            }
        }
    }

    int n = s.size();
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        int cur = 0;
        for (int r = l; r < n and r - l + 1 < 10; ++r) {
            cur <<= 1;
            if (s[r] == '1')
                cur |= 1;

            auto it = lower_bound(all(triple_free[r - l + 1]), cur);
            if (it != end(triple_free[r - l + 1]) and *it == cur) {
                ++ans;
            }
        }
    }
    
    ll out = 1LL * n * (n + 1) / 2 - ans;
    cout << out << '\n';

    return 0;
}
