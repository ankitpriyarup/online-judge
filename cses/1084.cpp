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

    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vi b(m);
    for (auto& y : b) {
        cin >> y;
    }
    sort(all(a));
    sort(all(b));

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m and b[j] + k < a[i]) {
            ++j;
        }
        if (j >= m)
            break;

        if (b[j] <= a[i] + k) {
            ++ans;
            ++j;
        }
    }

    cout << ans << '\n';
    return 0;
}
