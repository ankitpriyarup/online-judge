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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n;
int v[MAXN], l[MAXN], r[MAXN];
int par[MAXN];
map<int, int> freq;
int ans;

void dfs(int node, int minn = -1, int maxx = 1e9 + 7) {
    // printf("Valid range for node %d with value %d is (%d,%d)\n", node, v[node], minn, maxx);

    if (minn < v[node] and v[node] < maxx) {
        ans -= freq[v[node]];
    }

    if (l[node] != -1) {
        dfs(l[node], minn, min(maxx, v[node]));
    }

    if (r[node] != -1) {
        dfs(r[node], max(minn, v[node]), maxx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    memset(par, -1, sizeof(par));

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", v + i, l + i, r + i);

        if (l[i] != -1)
            par[l[i]] = i;
        if (r[i] != -1)
            par[r[i]] = i;

        ++freq[v[i]];
    }

    ans = n;
    for (int i = 1; i <= n; ++i)
        if (par[i] == -1)
            dfs(i);

    printf("%d\n", ans);

    return 0;
}
