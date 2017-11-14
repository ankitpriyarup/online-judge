#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1003;
int n, m;
int u[MAXN], v[MAXN], w[MAXN];
vector<pii> graph[MAXN];
int aug[MAXN];
int previous[MAXN];
bool on_path[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", u + i, v + i, w + i);
        graph[u[i]].push_back({v[i], w[i]});
        graph[v[i]].push_back({u[i], w[i]});
    }

    priority_queue<pii> pq;
    pq.push({1e9, 0});
    memset(aug, -1, sizeof(aug));
    memset(previous, -1, sizeof(previous));
    aug[0] = 1e9;

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if (aug[cur.second] != cur.first) continue;

        if (cur.second == n - 1) break;

        for (pii edge : graph[cur.second]) {
            int cap = min(cur.first, edge.second);

            if (aug[edge.first] == -1 || cap > aug[edge.first]) {
                aug[edge.first] = cap;
                pq.push({cap, edge.first});
                previous[edge.first] = cur.second;
            }
        }
    }

    int cur = n - 1;
    while (cur != 0) {
        // printf("%d on path\n", cur);
        on_path[cur] = true;
        cur = previous[cur];
    }
    on_path[0] = true;

    bool printed = false;
    for (int i = 0; i < m; ++i) {
        if (!on_path[u[i]] and !on_path[v[i]]) {
            continue;
        }

        if (on_path[u[i]] and on_path[v[i]] and (previous[u[i]] == v[i] || previous[v[i]] == u[i])) {
            continue;
        }

        printed = true;
        printf("%d ", i);
    }

    if (!printed)
        printf("none\n");

    return 0;
}
