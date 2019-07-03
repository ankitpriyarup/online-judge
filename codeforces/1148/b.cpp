#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n, m, ta, tb, k;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int ans = 0;
    for (int x = 0; x <= min(n, k); ++x) {
        if (x >= n) {
            ans = -1;
            break;
        }
        int y = k - x;
        if (y >= m) {
            ans = -1;
            break;
        }

        int s = a[x];
        int t = lower_bound(b, b + m, s + ta) - b;
        if (t + y >= m) {
            ans = -1;
            break;
        }
        ans = max(ans, b[t + y] + tb);
    }

    cout << ans << '\n';
    
    return 0;
}
