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

constexpr int MAXN = 1003;
int n, l, total;
int s, d;
vector<pair<int, pii> > graph[MAXN];
bool vis[MAXN];

bool bfs(int x) {
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == d) return true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            if (!vis[v] and edge.second.first <= x and x <= edge.second.second) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &l, &total);
    scanf("%d %d", &s, &d);
    int u, v, a, b;
    vector<int> inds;
    for (int i = 0; i < l; ++i) {
        scanf("%d %d %d %d", &u, &v, &a, &b);
        graph[u].push_back({v, {a, b}});
        // graph[v].push_back({u, {a, b}});

        for (int dd = -1; dd <= 1; ++dd) {
            inds.push_back(a + dd);
            inds.push_back(b + dd);
        }
    }

    inds.push_back(0);
    inds.push_back(1);
    inds.push_back(total);
    inds.push_back(total + 1);
    sort(begin(inds), end(inds));
    inds.erase(unique(begin(inds), end(inds)), end(inds));
    bool in_good = false;
    int last = 0;
    int ans = 0;
    for (int x : inds) {
        if (bfs(x)) {
            if (!in_good) {
                in_good = true;
                last = x;
            }
        } else {
            if (in_good) {
                ans += x - last;
                in_good = false;
            }
        }
    }
    
    printf("%d\n", ans);

    return 0;
}
