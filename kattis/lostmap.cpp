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

constexpr int MAXN = 2505;
int n;
int a[MAXN][MAXN];
int uf[MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);

    if (xr == yr) {
        return false;
    }

    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }

        uf[i] = i;
    }

    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back(make_tuple(a[i][j], i, j));
        }
    }

    sort(begin(edges), end(edges));

    int u, v, w;
    for (const auto& e : edges) {
        tie(w, u, v) = e;
        if (merge(u, v)) {
            printf("%d %d\n", u + 1, v + 1);
        }
    }
    
    return 0;
}
