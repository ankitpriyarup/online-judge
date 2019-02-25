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

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cur = 0;
        int h = (n + 1) >> 1;
        for (int i = 0; i < h; ++i) {
            cur += s[i] - '0';
        }
        int ans = cur;
        for (int i = h; i < n; ++i) {
            cur -= s[i - h] - '0';
            cur += s[i] - '0';
            ans = max(ans, cur);
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
