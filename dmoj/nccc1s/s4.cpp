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
using edge = tuple<int, int, int>;

constexpr int MAXN = 1003;
int n, m, k;
int s, t;
vector<edge> graph[MAXN];
bool vis[MAXN];

bool score(int x) {
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    q.push(s);
    vis[s] = true;

    // printf("Trying edge val %d\n", x);
    int v, a, b;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // printf("vis %d\n", u);

        if (u == t)
            return true;

        for (auto& e : graph[u]) {
            tie(v, a, b) = e;
            if (!vis[v] and a <= x and x <= b) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    scanf("%d %d", &s, &t);

    vector<int> all_vals;
    int u, v, a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &u, &v, &a, &b);
        graph[u].push_back({v, a, b});

        for (int d = -1; d <= 1; ++d) {
            all_vals.push_back(a + d);
            all_vals.push_back(b + d);
        }
    }
    all_vals.push_back(1);
    all_vals.push_back(k);
    sort(begin(all_vals), end(all_vals));
    all_vals.erase(unique(begin(all_vals), end(all_vals)), end(all_vals));

    vector<int> res;
    for (int val : all_vals) {
        res.push_back(score(val));
    }

    bool cond = false;
    int ans = 0;
    for (size_t i = 0; i < all_vals.size(); ++i) {
        // printf("%d %d\n", all_vals[i], res[i]);
        if (res[i]) {
            if (cond) {
                ans += all_vals[i] - all_vals[i - 1];
            } else {
                ++ans;
            }
        }

        cond = res[i];
    }

    printf("%d\n", ans);

    return 0;
}
