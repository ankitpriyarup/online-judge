#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

constexpr int MAXN = 50004;
int n, m;
vector<int> graph[MAXN];
int in_deg[MAXN];

namespace uf {
    int par[MAXN];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x] ? x : find(par[x]));
    }

    bool merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);

        if (xr == yr) return false;

        if (rand() % 2) {
            par[xr] = yr;
        } else {
            par[yr] = xr;
        }

        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    uf::init(n);

    vector<pii> edges;
    char buf[4];
    int comps = n;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %s %d", &u, buf, &v);

        if (buf[0] == '=') {
            if (uf::merge(u, v))
                --comps;
        } else {
            edges.push_back({u, v});
        }
    }

    for (auto edge : edges) {
        int u = uf::find(edge.first);
        int v = uf::find(edge.second);

        graph[u].push_back(v);
        ++in_deg[v];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (uf::par[i] == i and in_deg[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        --comps;
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (comps != 0) {
        printf("inconsistent\n");
    } else {
        printf("consistent\n");
    }

    return 0;
}
