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
    string s;
    cin >> n >> s;
    vector<vi> occ(26);
    for (int i = 0; i < n; ++i) {
        occ[s[i] - 'a'].push_back(i);
    }
    int j = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(all(occ[s[i] - 'a']), i) - begin(occ[s[i] - 'a']);
        if (idx != 0) {
            j = max(j, occ[s[i] - 'a'][idx - 1] + 1);
        }
        ans += i - j + 1;
    }
    cout << ans << '\n';
    
    return 0;
}
