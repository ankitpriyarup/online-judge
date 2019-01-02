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

constexpr int MAXN = 222;
int n;
int x[MAXN], y[MAXN], r[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    for (int v : graph[u])
        dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
        if (r[i] >= x[i]) {
            graph[n].push_back(i);
            graph[i].push_back(n);
        }
        if (x[i] + r[i] >= 200) {
            graph[n + 1].push_back(i);
            graph[i].push_back(n + 1);
        }

        for (int j = 0; j < i; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int rr = r[i] + r[j];
            if (dx * dx + dy * dy <= rr * rr) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        memset(vis, 0, sizeof(vis));
        for (int i = mid; i < n; ++i) {
            vis[i] = true;
        }

        dfs(n);
        if (!vis[n + 1]) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';

    return 0;
}
