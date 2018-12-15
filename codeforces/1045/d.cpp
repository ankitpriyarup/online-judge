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

constexpr int MAXN = 100005;
int n;
vector<int> tree[MAXN];
int par[MAXN];
double def[MAXN];
double child_sum[MAXN];

void dfs(int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;

        child_sum[u] += def[v];
        par[v] = u;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);

    double exp_v = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf(" %lf", &def[i]);
        def[i] = 1.0 - def[i];
        exp_v += def[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1);

    double exp_e = 0.0;
    for (int i = 0; i < n; ++i) {
        exp_e += def[i] * child_sum[i];
    }

    int q;
    scanf(" %d", &q);
    while (q-- > 0) {
        int x;
        double new_fall;
        scanf(" %d %lf", &x, &new_fall);

        exp_v -= def[x];
        exp_e -= def[x] * child_sum[x];
        if (x) {
            exp_e -= def[par[x]] * child_sum[par[x]];
            child_sum[par[x]] -= def[x];
        }

        def[x] = 1.0 - new_fall;

        if (x) {
            child_sum[par[x]] += def[x];
            exp_e += def[par[x]] * child_sum[par[x]];
        }

        exp_e += def[x] * child_sum[x];
        exp_v += def[x];

        printf("%.9lf\n", exp_v - exp_e);
    }

    return 0;
}
