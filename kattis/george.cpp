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

constexpr int MAXN = 1003;
int n, m, g;
vector<pii> graph[MAXN];
map<pii, pii> george;

int r[MAXN];
int times[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    int a, b, k;
    scanf("%d %d %d %d", &a, &b, &k, &g);
    for (int i = 0; i < g; ++i) {
        scanf("%d", r + i);
    }

    int cur, u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    times[0] = 0;
    for (int i = 0; i + 1 < g; ++i) {
        for (auto& e : graph[r[i]]) {
            if (e.first == r[i + 1]) {
                times[i + 1] = times[i] + e.second;
                george[{r[i], r[i + 1]}] = {times[i], times[i + 1]};
                george[{r[i + 1], r[i]}] = {times[i], times[i + 1]};
                break;
            }
        }
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    vector<int> dist(n + 1, -1);
    dist[a] = k;
    pq.push({dist[a], a});

    while (!pq.empty()) {
        tie(cur, u) = pq.top();
        pq.pop();


        if (cur != dist[u])
            continue;

        // printf("Visit node %d with dist %d\n", u, cur);

        for (auto& e : graph[u]) {
            tie(v, w) = e;
            int time = cur + w;
            if (george.find({u, v}) != end(george)) {
                // printf("George here! Path %d to %d blocked from %d to %d\n", u, v, george[{u, v}].first, george[{u, v}].second);
                if (cur >= george[{u, v}].first)
                    time = max(time, george[{u, v}].second + w);
            }

            if (dist[v] == -1 or time < dist[v]) {
                dist[v] = time;
                pq.push({dist[v], v});
            }
        }
    }

    printf("%d\n", dist[b] - k);

    return 0;
}
