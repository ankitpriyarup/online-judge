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

struct edge {
    double d;
    int u, v;

    bool operator<(const edge& other) const {
        return d < other.d;
    }
};

constexpr int MAXN = 800;
int n;
int uf[MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

bool unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;

    uf[xr] = yr;
    return true;
}

double dist(pair<double, double> a, pair<double, double> b) {
    double xd = a.first - b.first;
    double yd = a.second - b.second;
        
    return sqrt(xd * xd + yd * yd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        double x, y;
        vector<pair<double, double> > pts;
        vector<edge> edges;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);
            pts.push_back({x, y});
            for (int j = 0; j < i; ++j) {
                edges.push_back({dist(pts[j], pts.back()), j, i});
            }

            uf[i] = i;
        }

        sort(begin(edges), end(edges));

        double ans = 0.0;
        for (auto& e : edges) {
            if (unite(e.u, e.v)) {
                // printf("United %d and %d\n", e.u, e.v);
                ans += e.d;
            }
        }

        printf("%.9lf\n", ans);
    }
    
    return 0;
}
