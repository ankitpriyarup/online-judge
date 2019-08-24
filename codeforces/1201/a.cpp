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

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x : s)
        cin >> x;

    ll ans = 0;
    for (int j = 0; j < m; ++j) {
        vector<int> freq(5, 0);
        for (int i = 0; i < n; ++i) {
            ++freq[s[i][j] - 'A'];
        }

        int v;
        cin >> v;
        ans += 1LL * v * *max_element(all(freq));
    }

    cout << ans << '\n';
    
    return 0;
}
