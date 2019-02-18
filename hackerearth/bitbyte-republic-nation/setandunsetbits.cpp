#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // iterate over set and unset bits
    // only need 600k...
    // brute force?
    //
    // 1[set and unset combination]
    // how high do you need to go?
    /*
    ll binom[50][50];
    binom[0][0] = 1;
    for (int r = 1; r < 50; ++r) {
        binom[r][0] = binom[r][r] = 1;
        for (int c = 1; c < r; ++c) {
            binom[r][c] = binom[r - 1][c - 1] + binom[r - 1][c];
        }
    }

    ll have = 0LL;
    for (int len = 1; len <= 20; ++len) {
        for (int set = 1; set <= len; ++set) {
            int unset = len - set;
            if (gcd(set, unset) != 1) continue;

            ll ways = binom[set + unset - 1][unset];
            have += ways;
        }
    }

    cout << have << '\n';
    */

    vector<int> ans;
    for (int i = 0; i < (1 << 20); ++i) {
        int tot = 0;
        int set = 0;
        for (int j = 1; j <= i; j <<= 1) {
            if (i & j) ++set;
            ++tot;
        }
        int unset = tot - set;
        if (gcd(set, unset) == 1)
            ans.push_back(i);
    }

    // cout << ans.size() << '\n';

    int q;
    cin >> q;
    while (q-- > 0) {
        int x;
        cin >> x;
        --x;
        cout << ans[x] << '\n';
    }
    
    return 0;
}
