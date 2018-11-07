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
using edge = tuple<double, int, int>;

constexpr int MAXN = 2003;
int n, e, p;
double xx[MAXN], yy[MAXN];
int uf[MAXN];

double dist(int u, int v) {
    double dx = xx[u] - xx[v];
    double dy = yy[u] - yy[v];

    return sqrt(dx * dx + dy * dy);
}

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return 0;
    uf[xr] = yr;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d", &n, &e, &p);
    for (int i = 0; i < n; ++i) {
        scanf(" %lf %lf", &xx[i], &yy[i]);
        uf[i] = i;
    }
    for (int i = 1; i < e; ++i) {
        merge(i - 1, i);
    }
    int u, v;
    for (int i = 0; i < p; ++i) {
        scanf(" %d %d", &u, &v);
        --u; --v;
        merge(u, v);
    }

    double cost = 0.0;
    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (find(i) != find(j)) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
    }

    double w;
    sort(begin(edges), end(edges));
    for (auto& ed : edges) {
        tie(w, u, v) = ed;
        if (merge(u, v)) {
            cost += w;
        }
    }

    printf("%.12lf\n", cost);

    return 0;
}
