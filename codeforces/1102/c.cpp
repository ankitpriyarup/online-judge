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

    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(all(a));
    if (x <= y) {
        int ans = 0;
        vi b;
        for (int v : a) {
            if (v <= x)
                b.push_back(v);
        }
        int m = b.size();
        int p = 0;
        for (int i = m - 1; i >= 0; --i) {
            if (b[i] <= x) {
                ++ans;
            }

            while (p < i and b[p] > x)
                ++p;
            if (p < i)
                b[p] += y;
        }

        cout << ans << '\n';
    } else {
        cout << n << '\n';
    }

    return 0;
}
