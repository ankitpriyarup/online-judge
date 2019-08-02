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
    vi f(2, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                f[k] += 1 - (s[2 * k + l] - '0');
            }
        }
    }

    int ans = min(f[0], f[1]) / 2;
    cout << ans << ' ' << f[0] - 2 * ans << ' ' << f[1] - 2 * ans << '\n';
    
    return 0;
}
