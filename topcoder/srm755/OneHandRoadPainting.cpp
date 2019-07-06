#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

class OneHandRoadPainting {
public:
    ll fastest(vector<int> starts, vector<int> ends, int paintPerBrush) {
        int n = ends.size();
        int ptr = n - 1;
        int pos = ends[ptr];
        ll ans = 0LL;
        while (ptr >= 0) {
            // cerr << "At pos " << pos << '\n';
            ll t = (pos - starts[ptr]) / paintPerBrush;
            // cerr << "Can go " << t << " full times in this segment\n";
            // 2 * pos + 2 * (pos - p) + 2 * (pos - 2p) + ... 2 * (pos - t p)
            // 2 * [pos + (pos - p) + (pos - 2p) + ... + (pos - t p)]
            // 2 * [t * pos - (p + 2p + .. tp)]
            // 2 * [t * pos - p(t * (t + 1)) / 2]

            ans += 2LL * (t * pos - 1LL * t * (t - 1LL) / 2LL * paintPerBrush);
            // cerr << "ans now " << ans << '\n';

            pos -= t * paintPerBrush;
            if (pos == starts[ptr]) {
                --ptr;
                if (ptr >= 0) pos = ends[ptr];
                continue;
            }
            // cerr << "pos now " << pos << '\n';

            ans += pos;
            int paint = paintPerBrush;
            while (ptr >= 0 and paint > 0) {
                int in_seg = min(pos - starts[ptr], paint);
                paint -= in_seg;
                pos -= in_seg;
                ans += in_seg;

                if (pos == starts[ptr]) {
                    --ptr;
                    if (ptr < 0) break;

                    ans += starts[ptr + 1] - ends[ptr];
                    pos = ends[ptr];
                }
            }
            ans += pos;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    OneHandRoadPainting ohrp;
    ll x = ohrp.fastest({3, 7}, {4, 9}, 1);
    cout << x << '\n';

    return 0;
}
