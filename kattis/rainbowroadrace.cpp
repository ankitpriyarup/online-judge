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
using state = tuple<ll, int, int>;

string colors = "ROYGBIV";
constexpr int MAXN = 512;
int n, m;
vector<edge> graph[MAXN];
ll dist[MAXN][1 << 8];

inline int conv(char c) {
    return colors.find(c);
}

void read() {
    scanf(" %d %d", &n, &m);
    int u, v, w;
    char color;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d %c", &u, &v, &w, &color);
        int k = conv(color);
        graph[u].emplace_back(v, w, k);
        graph[v].emplace_back(u, w, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0LL, 1, 0);
    memset(dist, -1, sizeof(dist));
    dist[1][0] = 0;
    int u, v, w, mask, k;
    ll cur_dist;
    while (!pq.empty()) {
        tie(cur_dist, u, mask) = pq.top();
        pq.pop();
        if (dist[u][mask] != cur_dist) continue;
        for (auto& e : graph[u]) {
            tie(v, w, k) = e;
            ll new_dist = cur_dist + w;
            int new_mask = mask | (1 << k);
            if (dist[v][new_mask] == -1 or new_dist < dist[v][new_mask]) {
                dist[v][new_mask] = new_dist;
                pq.emplace(new_dist, v, new_mask);
            }
        }
    }

    printf("%lld\n", dist[1][(1 << 7) - 1]);

    return 0;
}
