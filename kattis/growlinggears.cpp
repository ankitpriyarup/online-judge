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

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;

        double best = -1;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            // ax^2 + bx + c
            // hits max when deriv. is 0
            // -2ax + b = 0
            // x = b / 2a
            double x = b / 2.0 / a;
            double val = -a * x * x + b * x + c;
            if (val > best) {
                best = val;
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
