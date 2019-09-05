#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vi need(2e5 + 1, 0);
    {
        int cur = 2;
        for (int i = 3; i < need.size(); ++i) {
            if ((i & (i - 1)) == 0) {
                ++cur;
            }
            need[i] = i - cur;
        }
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;

        int n = s.size();

        ll ans = 0LL;
        // for everything else, we need some number of zeros, then the binary number
        int zeros = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++zeros;
            } else {
                ll v = 0;
                int j = i;
                while (v <= n and j < n) {
                    v *= 2ll;
                    v += s[j] - '0';
                    ++j;

                    if (v >= need.size())
                        break;

                    if (need[v] <= zeros) {
                        ++ans;
                    }
                }
                zeros = 0;
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
