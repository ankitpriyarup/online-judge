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
    int ans = 0;
    for (int i = 0; i < 3; ++i)
        ans += s[i] == t[i];

    cout << ans << '\n';
    
    return 0;
}
