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
using edge = pair<int, ll>;

constexpr int MAXN = 10004;
int n, m;
vector<edge> graph[MAXN];
int degree[MAXN];
bool removed[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    int u, v;
    ll w;
    while (T-- > 0) {
        memset(degree, 0, sizeof(degree));
        memset(removed, 0, sizeof(removed));
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
        }

        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %lld", &u, &v, &w);
            ++degree[u];
            ++degree[v];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        for (int i = 1; i <= n; ++i) {
            sort(begin(graph[i]), end(graph[i]));
        }

        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 2) {
                removed[i] = true;

                int i1 = 0;
                while (removed[graph[i][i1].first]) ++i1;
                int i2 = i1 + 1;
                while (removed[graph[i][i2].first]) ++i2;

                u = graph[i][i1].first;
                v = graph[i][i2].first;
                w = graph[i][i1].second + graph[i][i2].second;

                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
        }

        vector<tuple<int, int, ll> > res;
        for (int i = 1; i <= n; ++i) {
            if (removed[i]) continue;
            for (auto e : graph[i]) {
                if (removed[e.first] or i > e.first) continue;
                res.push_back(make_tuple(i, e.first, e.second));
            }
        }

        sort(begin(res), end(res));
        res.erase(unique(begin(res), end(res)), end(res));
        printf("%d\n", res.size());
        for (auto t : res) {
            printf("%d %d %lld\n", get<0>(t), get<1>(t), get<2>(t));
        }

        printf("\n");
    }

    return 0;
}
