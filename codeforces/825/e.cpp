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
int n, m;
vector<int> graph[MAXN];
vector<int> rev[MAXN];
int p[MAXN];
int in_deg[MAXN];
int out_deg[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        rev[v].push_back(u);
        ++out_deg[u];
    }

    priority_queue<int> pq;
    for (int u = 1; u <= n; ++u) {
        if (out_deg[u] == 0)
            pq.push(u);
    }

    for (int label = n; label >= 1; --label) {
        int u = pq.top();
        pq.pop();

        p[u] = label;
        for (int v : rev[u])
            if (--out_deg[v] == 0)
                pq.push(v);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d%c", p[i], " \n"[i == n]);
    }

    return 0;
}
