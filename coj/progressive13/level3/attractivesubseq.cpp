#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
constexpr int MAXQ = 1001;
int a[MAXN];
int freq[MAXN * MAXQ];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        memset(freq, 0, sizeof(freq));
        freq[0] = 1;

        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] += a[i - 1];
            ++freq[a[i]];
        }

        while (q-- > 0) {
            int x;
            cin >> x;
            ll ans = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] != a[i - 1] and a[i] >= x) {
                    ans += 1LL * freq[a[i]] * freq[a[i] - x];
                }
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
