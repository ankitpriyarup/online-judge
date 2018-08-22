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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, h, l;
    scanf(" %d %d %d", &n, &h, &l);
    queue<int> q;
    int x;
    vector<int> dist(n, n * n);
    while (h-- > 0) {
        scanf(" %d", &x);
        dist[x] = 0;
        q.push(x);
    }

    vector<vector<int>> graph(n);
    int u, v;
    for (int i = 0; i < l; ++i) {
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (1 + dist[u] < dist[v]) {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (dist[i] > dist[ans])
            ans = i;

    printf("%d\n", ans);
    
    return 0;
}
