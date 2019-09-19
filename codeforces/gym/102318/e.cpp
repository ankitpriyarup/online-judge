#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr double TAU = 2.0 * 3.14159265358979;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int w, b, d, s;
        cin >> w >> b >> d >> s;

        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            double x, y;
            cin >> x >> y;

            double theta = atan2(y, x);
            double dist = hypot(x, y);
            if (theta < 0.0) {
                theta += TAU;
            }

            int score = 0;
            for (int j = 0; j < w; ++j) {
                double lo = j * TAU / w;
                double hi = (j + 1) * TAU / w;

                if (lo <= theta and theta <= hi) {
                    score = j + 1;
                    break;
                }
            }
            if (dist < b) {
                score = 50;
            } else if (dist < d) {
                score *= 2;
            } else if (dist > s) {
                score = 0;
            }

            ans += score;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
