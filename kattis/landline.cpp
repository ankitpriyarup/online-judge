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
int n, m, p;
bool is_insec[MAXN];

int uf[MAXN];

void init() {
    for (int i = 1; i <= n; ++i)
        uf[i] = i;
}

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return false;
    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d", &n, &m, &p);
    int u, v, w;
    for (int i = 0; i < p; ++i) {
        scanf(" %d", &u);
        is_insec[u] = true;
    }

    vector<edge> insecs, safe;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        if (is_insec[u] ^ is_insec[v]) {
            insecs.emplace_back(w, u, v);
        } else if ((!is_insec[u] and !is_insec[v]) or (p == n)) {
            safe.emplace_back(w, u, v);
        }
    }

    sort(begin(insecs), end(insecs));
    sort(begin(safe), end(safe));

    init();

    ll cost = 0;
    for (auto&& [w, u, v] : safe) {
        if (merge(u, v)) {
            cost += w;
        }
    }

    // ensure all the safe buildings are connected
    int safe_one = -1;
    for (int i = 1; i <= n; ++i) {
        if (!is_insec[i])
            safe_one = i;
    }

    if (safe_one != -1) {
        for (int i = 1; i <= n; ++i) {
            if (!is_insec[i] and find(safe_one) != find(i)) {
                printf("impossible\n");
                return 0;
            }
        }
    }

    for (auto&& [w, u, v] : insecs) {
        if (merge(u, v)) {
            cost += w;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (find(1) != find(i)) {
            printf("impossible\n");
            return 0;
        }
    }

    printf("%lld\n", cost);
    return 0;
}
