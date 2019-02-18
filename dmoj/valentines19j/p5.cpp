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

    vi m(n), b(n);
    map<int, int> freq;
    map<pii, int> freq2;
    for (int i = 0; i < n; ++i) {
        cin >> m[i] >> b[i];
        ++freq[m[i]];
        ++freq2[make_pair(m[i], b[i])];
    }

    // two lines intersect if m[i] != m[j] or m[i] == m[j] and b[i] == b[j]
    ll ans = 1LL * n * (n - 1) / 2LL;
    for (auto& p : freq) {
        int x = p.second;
        ans -= 1LL * x * (x - 1) / 2LL;
    }
    for (auto& p : freq2) {
        int x = p.second;
        ans += 1LL * x * (x - 1) / 2LL;
    }

    cout << ans << '\n';
    
    return 0;
}
