#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n, m;
void solve() {
    // order of columns doesn't matter
    // sort the columns lexicographically descending
    // put the biggest value of the biggest column in the upper left. 
    // That fixes the left column
    // for subsequent columns, only so many places they could go
    // DP: bitmask which rows are fixed
    //
    // Sort columns by max value
    // process big to small, which ones are locked in, every rotation
    // 2^12 * 2000 states, but should be much smaller since you dont need more than 12 columns

    cin >> n >> m;
    vector<vi> columns(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            columns[j].push_back(x);
        }
    }
    for (int j = 0; j < m; ++j) {
        auto it = max_element(all(columns[j]));
        rotate(begin(columns[j]), it, end(columns[j]));
    }

    sort(all(columns), [](const vi& a, const vi& b) {
        return a[0] > b[0];
    });

    while (columns.size() > n) {
        columns.pop_back();
    }

    // for each column, for each mask, precompute best rotation
    vector<vi> cost(columns.size(), vi(1 << n, 0));
    for (int j = 0; j < columns.size(); ++j) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int rot = 0; rot < n; ++rot) {
                int cur = 0;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        cur += columns[j][(i + rot) % n];
                    }
                }

                cost[j][mask] = max(cost[j][mask], cur);
            }
        }
    }

    vi dp = cost[0];
    for (int i = 1; i < columns.size(); ++i) {
        vi new_dp(1 << n, 0);
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                int other = mask ^ sub;

                new_dp[mask] = max(new_dp[mask], dp[sub] + cost[i][other]);
            }
        }

        swap(dp, new_dp);
    }

    cout << dp.back() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
