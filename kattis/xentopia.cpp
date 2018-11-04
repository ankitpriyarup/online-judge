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
using state = tuple<ll, int, int, int>;

constexpr int MAXN = 455;
int n;
vector<edge> graph[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, k1, k2;
    scanf(" %d %d %d %d", &n, &m, &k1, &k2);
    int u, v, w, c;
    while (m-- > 0) {
        scanf(" %d %d %d %d", &u, &v, &w, &c);
        graph[u].emplace_back(v, w, c);
        graph[v].emplace_back(u, w, c);
    }

    int s, t;
    scanf(" %d %d", &s, &t);
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0, s, 0, 0);
    map<edge, ll> dist;

    ll cur_dist;
    int r, b;
    while (!pq.empty()) {
        tie(cur_dist, u, r, b) = pq.top();
        pq.pop();
        edge cur = make_tuple(u, r, b);
        if (r > k1 or b > k2 or dist.find(cur) != end(dist))
            continue;

        if (u == t and r == k1 and b == k2) {
            printf("%lld\n", cur_dist);
            return 0;
        }
        dist[cur] = cur_dist;
        for (auto& e : graph[u]) {
            tie(v, w, c) = e;
            ll new_dist = cur_dist + w;
            int nr = r + (c == 1);
            int nb = b + (c == 2);
            edge next_edge = make_tuple(v, nr, nb);
            if (dist.find(next_edge) == end(dist)) {
                pq.emplace(new_dist, v, nr, nb);
            }
        }
    }

    printf("%d\n", -1);
    return 0;
}
