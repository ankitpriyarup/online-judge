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
    string s;
    cin >> s;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int ans = 0;
    for (int t = 0; t < 5040; ++t) {
        int cur = 0;
        for (char c : s) {
            cur += c - '0';
        }
        ans = max(ans, cur);

        for (int i = 0; i < n; ++i) {
            if (b[i] <= t and (t - b[i]) % a[i] == 0) {
                s[i] ^= 1;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
