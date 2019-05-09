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
    ll z;
    cin >> n >> z;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (2 * mid > n) {
            hi = mid;
            continue;
        }
        int gap = n - mid;
        bool valid = true;
        for (int i = 0; i < mid; ++i) {
            if (a[i] + z > a[i + gap]) {
                valid = false;
            }
        }

        if (valid) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';

    return 0;
}
