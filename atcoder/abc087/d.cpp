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

constexpr int MAXN = 100005;
int n, m;
vector<pii> graph[MAXN];
int in_deg[MAXN];
int uf[MAXN];
int dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        uf[i] = i;

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        ++in_deg[v];
    }

    queue<int> q;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
    }

    bool valid = true;
    while (valid and !q.empty()) {
        int u = q.front();
        q.pop();

        for (const pii& p : graph[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push(v);
            } else {
                valid &= (dist[v] == dist[u] + w);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        valid &= dist[i] != -1;
    }

    printf("%s\n", valid ? "Yes" : "No");

    return 0;
}
