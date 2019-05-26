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

    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int lo = -1;
    int hi = m;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int last = 0;
        bool valid = true;

        // cout << "Mid: " << mid << '\n';
        for (int i = 0; i < n; ++i) {
            if (a[i] + mid >= m) {
                int x = a[i];
                int y = (a[i] + mid) - m;
                // cout << "split x y " << x << " " << y << '\n';
                if (x <= last or last <= y) {
                    continue;
                } else {
                    last = x;
                }
            } else {
                int x = a[i];
                int y = a[i] + mid;
                // cout << "range x y " << x << " " << y << '\n';
                if (y < last) {
                    // cout << "BAD\n";
                    valid = false;
                    break;
                }

                last = max(last, x);
            }
        }

        if (valid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';

    return 0;
}
