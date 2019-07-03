#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll s;
    while (cin >> n >> s) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int r = 0;
        ll sum = a[0];
        bool found = false;
        for (int l = 0; l < n; ++l) {
            while (r + 1 < n and sum + a[r + 1] <= s) {
                ++r;
                sum += a[r];
            }

            if (sum == s) {
                found = true;
                cout << (l + 1) << ' ' << (r + 1) << '\n';
                break;
            }

            sum -= a[l];
            if (r == l and r + 1 < n) {
                ++r;
                sum = a[r];
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }

    return 0;
}
