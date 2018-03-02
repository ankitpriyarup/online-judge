#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int INF = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0)
            break;

        vector<pair<string, string> > name_edges;
        vector<string> all_names;
        string a, b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            name_edges.push_back(make_pair(a, b));
            all_names.push_back(a);
            all_names.push_back(b);
        }

        sort(begin(all_names), end(all_names));
        all_names.erase(unique(begin(all_names), end(all_names)), end(all_names));

        /*
        for (const auto& s : all_names) {
            cout << s << '\n';
        }
        */

        vector<vector<bool> > adj(n, vector<bool>(n, false));
        for (const auto& p : name_edges) {
            int x = lower_bound(begin(all_names), end(all_names), p.first) - begin(all_names);
            int y = lower_bound(begin(all_names), end(all_names), p.second) - begin(all_names);
            adj[x][y] = true;
            adj[y][x] = true;
        }

        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adj[i][j];
            }
            cout << '\n';
        }
        */

        vector<int> dp(1 << n, INF);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            bool valid = true;
            for (int i = 0; valid and i < n; ++i) {
                if ((mask & (1 << i)) == 0)
                    continue;

                for (int j = i + 1; j < n; ++j) {
                    if ((mask & (1 << j)) == 0)
                        continue;

                    if (adj[i][j]) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
                dp[mask] = 1;
        }

        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                dp[mask] = min(dp[mask], dp[sub] + dp[mask ^ sub]);
            }

            // printf("dp[%x] = %d\n", mask, dp[mask]);
        }

        cout << dp[(1 << n) - 1] << '\n';
    }
    
    return 0;
}
