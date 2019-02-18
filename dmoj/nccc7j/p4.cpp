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

    string s, t;
    cin >> s >> t;
    vector<int> f(26, 0);
    for (char c : s) {
        ++f[c - 'A'];
    }
    for (char c : t) {
        --f[c - 'A'];
    }

    int ans = 0;
    for (int x : f) {
        ans += max(0, x);
    }

    cout << ans << '\n';
    
    return 0;
}
