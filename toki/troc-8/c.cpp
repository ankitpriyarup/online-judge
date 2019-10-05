#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<vi> can(26, vi(26, 0));

    for (int i = 0; i < n; ++i) {
        can[t[i] - 'A'][s[i] - 'a'] = true;
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int opts = 1;
        for (int j = 0; j < 26; ++j) {
            opts += can[t[i] - 'A'][j];
        }

        ans = 1LL * ans * opts % MOD;
    }

    cout << ans << '\n';
    
    return 0;
}
