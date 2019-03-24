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

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi acs(n, 0);

    for (int i = 1; i < n; ++i) {
        acs[i] = acs[i - 1];
        if (s[i - 1] == 'A' and s[i] == 'C')
            ++acs[i];
    }

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int ans = acs[r] - (l == 0 ? 0 : acs[l - 1]);
        if (l > 0 and s[l - 1] == 'A' and s[l] == 'C')
            --ans;

        cout << ans << '\n';
    }
    
    return 0;
}
