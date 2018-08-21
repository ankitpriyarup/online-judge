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

constexpr int MAXN = 1000006;

// Union find structure for Kruskal's algorithm
namespace uf {
    int uf[2 * MAXN];
    int sz[2 * MAXN];
    int num_edges[2 * MAXN];
    pair<int, int> caps[2 * MAXN];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            uf[i] = i;
            caps[i] = {-1, i};
            num_edges[i] = 0;
            sz[i] = 1;
        }
    }

    int find(int x) {
        return uf[x] = x == uf[x] ? x : find(uf[x]);
    }

    bool join(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        ++num_edges[xr];
        if (xr == yr)
            return false;

        vector<int> all_caps;
        all_caps.push_back(caps[xr].first);
        all_caps.push_back(caps[xr].second);
        all_caps.push_back(caps[yr].first);
        all_caps.push_back(caps[yr].second);

        sort(begin(all_caps), end(all_caps));

        /*
        printf("Merging comp %d %d %d {%d, %d} with comp %d %d %d {%d, %d}\n", 
                xr, sz[xr], num_edges[xr], caps[xr].first, caps[xr].second,
                yr, sz[yr], num_edges[yr], caps[yr].first, caps[yr].second);
        */

        pair<int, int> new_caps = {all_caps[2], all_caps[3]};

        if (sz[xr] >= sz[yr]) {
            uf[y] = uf[yr] = xr;
            sz[xr] += sz[yr];
            num_edges[xr] += num_edges[yr];
            caps[xr] = new_caps;
        } else {
            uf[x] = uf[xr] = yr;
            sz[yr] += sz[xr];
            num_edges[yr] += num_edges[xr];
            caps[yr] = new_caps;
        }
        return true;
    }
}

int n;
int m;
int a[MAXN], b[MAXN];
int times[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);

    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &a[i], &b[i]);
        times[2 * i] = a[i];
        times[2 * i + 1] = b[i];
    }

    int nn = n + n;
    sort(times, times + nn);
    m = unique(times, times + nn) - times;
    uf::init(m);

    for (int i = 0; i < n; ++i) {
        // printf("Old %d %d, ", a[i], b[i]);
        a[i] = lower_bound(times, times + m, a[i]) - times;
        b[i] = lower_bound(times, times + m, b[i]) - times;
        // printf("New %d %d\n", a[i], b[i]);
        uf::join(a[i], b[i]);
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (uf::uf[i] != i) continue;

        int e = uf::num_edges[i];
        int v = uf::sz[i];

        // printf("Comp with %d has %d vert and %d edges\n", i, v, e);

        if (e > v) {
            printf("-1\n");
            return 0;
        } else if (e == v) {
            ans = max(ans, uf::caps[i].second);
        } else {
            ans = max(ans, uf::caps[i].first);
        }
    }

    printf("%d\n", times[ans]);
    return 0;
}
