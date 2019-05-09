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
    vi s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    vi have(11, 0);
    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        have[x] = true;
    }

    for (int i = 1; i <= 10; ++i)
        if (have[i - 1]) 
            have[i] = true;

    int ans = 10;
    for (int v : s) {
        if (!have[v])
            ans = min(ans, v);
    }

    cout << ans << '\n';
    
    return 0;
}
