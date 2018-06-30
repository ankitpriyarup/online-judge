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

constexpr int MAXN = 200005;
int n, m;
// outgoing (+0) at A, going through B or C
//   first is node, second is 0 if going to B and 1 if going to C
// incoming (+1) at B or C going through A
//   first is node, second is 0
vector<pii> graph[MAXN];
int dist[MAXN];
int before[MAXN];

void bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    before[0] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // printf("Process %d, %d\n", 1 + (u >> 1), (u & 1));
        for (auto&& [v, id] : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                before[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    string u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        char u_last = u.back();
        u.pop_back();
        char v_last = v.back();
        v.pop_back();

        int u_add = u_last == 'A';
        int v_add = v_last != 'A';

        int uu = stoi(u);
        int vv = stoi(v);
        --uu; --vv;
        if (!u_add)
            graph[2 * uu + u_add].emplace_back(2 * vv + v_add, u_last == 'C');
        else
            graph[2 * uu + u_add].emplace_back(2 * vv + v_add, 0);

        if (v_add)
            graph[2 * vv + (1 - v_add)].emplace_back(2 * uu + (1 - u_add), v_last == 'C');
        else
            graph[2 * vv + (1 - v_add)].emplace_back(2 * uu + (1 - u_add), 0);

        /*
        printf("Edge (%d, %d) (%d, %d)\n", 1 + uu, u_add, 1 + vv, v_add);
        printf("Edge (%d, %d) (%d, %d)\n", 1 + vv, 1 - v_add, 1 + uu, 1 - u_add);
        */
    }

    // bfs from 0 to 0
    bfs();

    // find the last node
    int last = -1;
    for (int u = 1; u < 2 * n; ++u) {
        // printf("dist[%d, %d] = %d\n", 1 + (u >> 1), (u & 1), dist[u]);
        if (dist[u] == -1) continue;

        for (auto&& [v, id] : graph[u]) {
            if (v == 0) {
                if (last == -1 or dist[u] < dist[last]) {
                    last = u;
                }
            }
        }
    }

    if (last == -1) {
        cout << "Impossible\n";
        return 0;
    }

    string res(n, 'B');
    for (auto&& [v, id] : graph[last]) {
        if (v == 0) {
            if (id)
                res[last >> 1] = 'C';
        }
    }

    while (last != 0) {
        int b = before[last];
        // printf("%d %d\n", 1 + (last >> 1), last & 1);
        for (auto&& [v, id] : graph[b]) {
            if (v == last) {
                if (id)
                    res[b >> 1] = 'C';

                break;
            }
        }
        last = b;
    }

    cout << res << '\n';
    return 0;
}
