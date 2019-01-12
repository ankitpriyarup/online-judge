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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur += a[i];
            } else {
                cur -= a[i];
            }
        }

        if (cur % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
