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

constexpr int MAXN = 1e6 + 6;
int uf[MAXN];

vector<int> graph[MAXN];
int in_deg[MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;
    uf[xr] = yr;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            uf[i * m + j] = i * m + j;
        }
    }

    vector<pii> v(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[j] = {a[i][j], j};
        }

        sort(begin(v), end(v));
        for (int j = 1; j < m; ++j) {
            if (v[j].first == v[j - 1].first) {
                merge(i * m + v[j].second, i * m + v[j - 1].second);
            }
        }
    }

    v.resize(n);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            v[i] = {a[i][j], i};
        }

        sort(begin(v), end(v));
        for (int i = 1; i < n; ++i) {
            if (v[i].first == v[i - 1].first) {
                merge(v[i].second * m + j, v[i - 1].second * m + j);
            }
        }
    }

    v.resize(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[j] = {a[i][j], j};
        }

        sort(begin(v), end(v));
        for (int j = 1; j < m; ++j) {
            if (v[j].first > v[j - 1].first) {
                int lo = find(i * m + v[j - 1].second);
                int hi = find(i * m + v[j].second);
                graph[lo].push_back(hi);
                ++in_deg[hi];
            }
        }
    }

    v.resize(n);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            v[i] = {a[i][j], i};
        }

        sort(begin(v), end(v));
        for (int i = 1; i < n; ++i) {
            if (v[i].first > v[i - 1].first) {
                int lo = find(v[i - 1].second * m + j);
                int hi = find(v[i].second * m + j);
                graph[lo].push_back(hi);
                ++in_deg[hi];
            }
        }
    }

    queue<int> q;
    for (int x = 0; x < n * m; ++x) {
        if (uf[x] == x and in_deg[x] == 0)
            q.push(x);
    }

    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (--in_deg[v] == 0)
                    q.push(v);
            }
        }
        ++lvl;
    }

    printf("%d\n", lvl);

    return 0;
}
