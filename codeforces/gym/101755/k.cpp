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

    auto sold = [&](int x) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur >= a[i]) {
                ++cur;
            } else if (x > 0) {
                ++cur;
                --x;
            }
        }

        return cur;
    };

    int lo = -1;
    int hi = n;

    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (sold(mid) >= m) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';
    
    return 0;
}
