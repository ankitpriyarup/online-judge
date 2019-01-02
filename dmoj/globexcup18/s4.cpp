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

constexpr int MAXN = 18;
bitset<1 << MAXN> vis[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, v;
    cin >> n >> m >> a >> b >> v;
    --a; --b;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int uu, vv;
        cin >> uu >> vv;
        --uu; --vv;
        graph[uu].push_back(vv);
        graph[vv].push_back(uu);
    }

    // dp[mask][last][dist] => bool
    using state = tuple<int, int, int>;
    vis[a][0][1 << a] = true;
    queue<state> q;
    q.emplace(a, 0, 1 << a);
    int last, dist, mask;
    while (!q.empty()) {
        tie(last, dist, mask) = q.front();
        q.pop();

        for (int u : graph[last]) {
            int new_mask = mask | (1 << u);
            if (mask == new_mask) continue;
            if (!vis[u][dist + 1][new_mask]) {
                vis[u][dist + 1][new_mask] = true;
                q.emplace(u, dist + 1, new_mask);
            }
        }
    }

    int best = n + n;
    int ans = n + n;
    for (int d = 0; d < n; ++d) {
        for (mask = 0; mask < (1 << n); ++mask) {
            if (vis[b][d][mask]) {
                if (abs(v - d) < best) {
                    best = abs(v - d);
                    ans = d;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
