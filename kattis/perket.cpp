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
    vi s(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> b[i];
    }

    int ans = 1e9 + 7;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sour = 1;
        int bitter = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sour *= s[i];
                bitter += b[i];
            }
        }

        ans = min(ans, abs(sour - bitter));
    }

    cout << ans << '\n';
    
    return 0;
}
