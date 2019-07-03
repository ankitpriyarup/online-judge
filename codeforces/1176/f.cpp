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

    // ways to get < 3:
    // 1:
    // 1
    //
    // 2:
    // 1 1
    // 2
    //
    // 3:
    // 1 1 1
    // 1 2
    // 3

    vector<vi> moves = {{1, 0, 0}, {2, 0, 0}, {0, 1, 0}, {3, 0, 0}, {1, 1, 0}, {0, 0, 1}};
    int n;
    cin >> n;

    constexpr ll INF = 1e16;
    vector<ll> dp(10, -INF);
    dp[0] = 0;

    for (int t = 0; t < n; ++t) {
        int k;
        cin >> k;
        vector<vi> by_cost(3);
        for (int i = 0; i < k; ++i) {
            int c, d;
            cin >> c >> d;
            by_cost[c - 1].push_back(d);
        }

        for (int j = 0; j < 3; ++j) {
            sort(all(by_cost[j]));
            reverse(all(by_cost[j]));
        }

        vector<ll> ndp(all(dp));
        for (const vi& move : moves) {
            bool valid = true;
            for (int j = 0; valid and j < 3; ++j) {
                valid &= by_cost[j].size() >= move[j];
            }
            if (!valid) continue;

            ll cur_dmg = 0;
            ll max_card = 0;
            int cards = 0;
            for (int j = 0; j < 3; ++j) {
                for (int i = 0; i < move[j]; ++i) {
                    ++cards;
                    cur_dmg += by_cost[j][i];
                    max_card = max(max_card, (ll)by_cost[j][i]);
                }
            }

            ll bonus = cur_dmg + max_card;
            for (int i = 0; i < 10; ++i) {
                int j = i + cards;
                if (j >= 10) {
                    ndp[j - 10] = max(ndp[j - 10], dp[i] + bonus);
                } else {
                    ndp[j] = max(ndp[j], dp[i] + cur_dmg);
                }
            }
        }

        swap(dp, ndp);

        /*
        for (int i = 0; i < 10; ++i) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
        */
    }

    ll ans = 0;
    for (ll x : dp) {
        ans = max(ans, x);
    }

    cout << ans << '\n';

    return 0;
}
