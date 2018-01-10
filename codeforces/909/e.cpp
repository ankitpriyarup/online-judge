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
int kind[MAXN];
vector<int> graph[MAXN];
int in_deg[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", kind + i);
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[v].push_back(u);
        ++in_deg[u];
    }

    queue<int> q[2];
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            q[kind[i]].push(i);
        }
    }

    int ans = 0;
    while (!q[0].empty() or !q[1].empty()) {
        // execute all the main processor tasks
        while (!q[0].empty()) {
            int u = q[0].front();
            q[0].pop();
            for (int v : graph[u]) {
                if (--in_deg[v] == 0) {
                    q[kind[v]].push(v);
                }
            }
        }

        // execute all the coproc tasks
        if (!q[1].empty()) {
            while (!q[1].empty()) {
                int u = q[1].front();
                q[1].pop();
                for (int v : graph[u]) {
                    if (--in_deg[v] == 0) {
                        q[kind[v]].push(v);
                    }
                }
            }
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
