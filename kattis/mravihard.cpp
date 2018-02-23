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
    int v, x, t;
};

constexpr int MAXN = 1003;
int n;
vector<edge> tree[MAXN];
ld needed[MAXN];

bool flow(int u, ld amt, int par = -1) {
    if (needed[u] > 0.0 and amt < needed[u])
        return false;

    for (auto& e : tree[u]) {
        if (e.v == par) continue;

        ld goop = amt * e.x / 100.0;
        if (e.t)
            goop = max(goop, goop * goop);

        if (!flow(e.v, goop, u)) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int u, v, x, t;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d %d", &u, &v, &x, &t);
        tree[u].push_back({v, x, t});
        tree[v].push_back({u, x, t});
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%Lf", needed + i);
    }

    ld lo = 0.0L;
    ld hi = 1e15;

    for (int iter = 0; iter < 200; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        if (flow(1, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.17Lf\n", hi);

    return 0;
}
