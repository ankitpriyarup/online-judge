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
using pii = pair<int, int>;

constexpr int MAXN = 1003;
int n;
struct pt {
    ll x, y;
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
    ll cross(const pt& other) const {
        return x * other.y - y * other.x;
    }
};

struct seg {
    pt a, b;
} segs[MAXN];

vector<int> graph[MAXN];

ll ccw(const pt& a, const pt& b, const pt& c) {
    ll ret = (b - a).cross(c - a);
    return ret == 0 ? ret : (ret > 0 ? 1 : -1);
}

bool intersect(int i, int j) {
    return ccw(segs[i].a, segs[j].a, segs[j].b) != ccw(segs[i].b, segs[j].a, segs[j].b)
        and ccw(segs[j].a, segs[i].a, segs[i].b) != ccw(segs[j].b, segs[i].a, segs[i].b);
}

int verts, edges;
bool vis[MAXN];
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    if (graph[u].empty()) return;

    verts += graph[u].size();
    edges += graph[u].size() - 1;
    for (int v : graph[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld %lld", &segs[i].a.x, &segs[i].a.y, &segs[i].b.x, &segs[i].b.y);

        for (int j = 0; j < i; ++j) {
            if (intersect(i, j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            verts = 0;
            edges = 0;
            dfs(i);
            if (verts == 0) continue;
            verts /= 2;
            // printf("Found %d verts and %d edges\n", verts, edges);
            // v - e + f = 1
            // f = 1 - v + e
            ans += edges - verts + 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
