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
using vi = vector<int>;

constexpr int MAXN = 200005;
int n, m;
// -1 is unset, 0 is off, 1 is on
// 2 is red, 3 is blue
int color[MAXN];

vector<int> graph[MAXN];

void prop(int u) {
    for (int v : graph[u]) {
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            // printf("Setting %d to %d\n", v, color[v]);
            prop(v);
        }
    }
}

pii dfs(int u, int c = 2) {
    pii res = {0, 0};
    if (c == 2) {
        res.first += 1;
    } else {
        res.second += 1;
    }

    color[u] = c;
    // printf("Setting %d to %d\n", u, color[u]);
    for (int v : graph[u]) {
        if (color[v] == -1) {
            pii cc = dfs(v, 5 - c);
            res.first += cc.first;
            res.second += cc.second;
        }
    }

    return res;
}

template <class F>
void fix(int u, F f) {
    color[u] = f(color[u]);
    // printf("Setting %d to %d\n", u, color[u]);
    for (int v : graph[u]) {
        if (color[v] >= 2) {
            fix(v, f);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);

    int u, v, c;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &c);
        if (c == 0) {
            if (color[u] == 1 or color[v] == 1) {
                return printf("impossible\n"), 0;
            }
            color[u] = 0;
            color[v] = 0;
        } else if (c == 1) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        } else {
            if (color[u] == 0 or color[v] == 0) {
                return printf("impossible\n"), 0;
            }
            color[u] = 1;
            color[v] = 1;
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (color[u] == 0 or color[u] == 1) {
            prop(u);
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (color[u] == -1) {
            pii res = dfs(u);
            if (res.first > res.second) {
                fix(u, [](const int& x) { return x - 2; } );
            } else {
                fix(u, [](const int& x) { return 3 - x; } );
            }
        }
    }

    bool poss = true;
    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        assert(0 <= color[u] and color[u] <= 1);
        ans += color[u];
        for (int v : graph[u]) {
            if (color[u] == color[v])
                poss = false;
        }
    }

    if (!poss) {
        printf("impossible\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
