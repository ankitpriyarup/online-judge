#include <iostream>

using namespace std;

int n, m;
int c[20];

int dp_single[1 << 19];
int dp[1 << 19];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> m;
        memset(dp_single, 0x3f, sizeof(dp_single));
        dp_single[0] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            dp_single[1 << i] = c[i];
        }

        int p, q, x, set;
        for (int i = 0; i < m; ++i) {
            cin >> p >> q;
            set = 0;
            while (q-- > 0) {
                cin >> x;
                set |= (1 << (x - 1));
            }

            dp_single[set] = min(dp_single[set], p);
        }

        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    dp_single[mask ^ (1 << i)] = min(dp_single[mask], dp_single[mask ^ (1 << i)]);
            }
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
            dp[mask] = dp_single[mask];
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    int old_mask = mask ^ (1 << i);
                    dp[mask] = min(dp[mask], dp[old_mask] + c[i]);
                }
            }

            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                dp[mask] = min(dp[mask], dp[submask] + dp_single[mask ^ submask]);
            }
        }

        cout << dp[(1 << n) - 1] << '\n';
    }

    return 0;
}
