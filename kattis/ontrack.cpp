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

constexpr int MAXN = 10004;
int n;
vector<int> tree[MAXN];
vector<int> sizes[MAXN];
int sz[MAXN];

void dfs(int u, int par) {
    sz[u] = 1;
    for (int v : tree[u]) {
        if (v == par) continue;
        dfs(v, u);
        sz[u] += sz[v];

        sizes[u].push_back(sz[v]);
    }

    if (par != -1)
        sizes[u].push_back(n - sz[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    ++n;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1);

    ll worst = 0;
    ll fix = 0;
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        ll total = 0;
        sort(begin(sizes[i]), end(sizes[i]));
        // printf("%d: ", i);
        for (int x : sizes[i]) {
            total += sum * x;
            sum += x;
            // printf("%d", x);
        }
        // printf("\n");

        if (total > worst) {
            worst = total;
            int x = sizes[i][sizes[i].size() - 1];
            int y = sizes[i][sizes[i].size() - 2];

            fix = worst - 1LL * x * y;
        }
    }

    printf("%lld %lld\n", worst, fix);

    return 0;
}
