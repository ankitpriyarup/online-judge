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

constexpr int MAXN = 200005;
int n, m;
vector<int> graph[MAXN];
int forced[MAXN];

void read() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        graph[2 * i].clear();
        graph[2 * i + 1].clear();
    }

    memset(forced, -1, sizeof(forced));
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        if (u > 0) {
            graph[2 * u].push_back(2 * v + 1);
        } else {
            u = -u;
            graph[2 * u].push_back(2 * v);
            graph[2 * u + 1].push_back(2 * v + 1);
            forced[u] = v;
        }
    }

    for (int i = 1; i <= n; ++i) {
        graph[2 * i].push_back(2 * i + 1);
    }
}

bool seen[MAXN];

void solve() {
    queue<int> q;
    memset(seen, false, sizeof(seen));
    q.push(2);
    seen[2] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // printf("Visit node %d not free %d\n", cur >> 1, cur & 1);

        for (int child : graph[cur]) {
            if (!seen[child]) {
                seen[child] = true;
                q.push(child);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (seen[2 * i + 1] and forced[i] == -1) {
            ++ans;
        }
    }

    printf("%d\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    solve();

    return 0;
}
