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

    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    ll lo = 0;
    ll hi = 1e16;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) >> 1;
        int blocks = 0;
        ll cur = 0LL;
        for (int i = 0; i < n; ++i) {
            if (a[i] > mid) {
                blocks = n + n;
                break;
            }

            if (cur + a[i] > mid) {
                ++blocks;
                cur = a[i];
            } else {
                cur += a[i];
            }
        }

        if (cur > 0)
            ++blocks;

        if (blocks > k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << hi << '\n';

    return 0;
}
