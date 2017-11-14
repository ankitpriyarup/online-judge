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
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 50004;
int n, m;
bool is_bad[MAXN];
vi graph[MAXN];
set<int> dag[MAXN];
vi val, comp, z;
vi comps[MAXN];
bool visit[MAXN];
bool bad_comp[MAXN];
int in_deg[MAXN];
int timer, ncomps;

int dfs(int j) {
    int low = val[j] = ++timer, x;
    z.push_back(j);
    for (int e : graph[j])
        if (comp[e] < 0)
            low = min(low, val[e] ?: dfs(e));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            comps[ncomps].push_back(x);
        } while (x != j);
        ++ncomps;
    }

    return val[j] = low;
}

void scc() {
    val.assign(n, 0);
    comp.assign(n, -1);
    timer = ncomps = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] < 0) {
            dfs(i);
        }
    }
}

void dfs2(int c) {
    if (visit[c]) return;
    visit[c] = true;

    for (int node : comps[c]) {
        if (is_bad[node]) {
            bad_comp[c] = true;
            break;
        }
    }

    for (int child : dag[c]) {
        dfs2(child);
        if (bad_comp[child]) bad_comp[c] = true;
    }
}

int fin_ans;

void mark(int u) {
    if (visit[u]) return;
    visit[u] = true;

    for (int v : dag[u]) {
        mark(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int bad, u, v;
    scanf("%d %d %d", &n, &bad, &m);
    for (int i = 0; i < m; ++i) { 
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    int x;
    while (bad-- > 0) {
        scanf("%d", &x);
        is_bad[x] = true;
    }

    scc();
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (comp[u] != comp[v]) {
                int old_sz = dag[comp[u]].size();
                dag[comp[u]].insert(comp[v]);
                // printf("Edge from %d to %d\n", comp[u], comp[v]);
                if (old_sz != dag[comp[u]].size())
                    ++in_deg[comp[v]];
            }
        }
    }

    for (int c = 0; c < ncomps; ++c) {
        if (in_deg[c] == 0) {
            dfs2(c);
        }
    }

    memset(visit, 0, sizeof(visit));
    fin_ans = 0;
    deque<int> q;
    for (int c = 0; c < ncomps; ++c) {
        if (in_deg[c] == 0) {
            if (bad_comp[c])
                q.push_back(c);
            else
                q.push_front(c);
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop_front();

        if (!visit[c]) {
            if (bad_comp[c]) {
                for (int node : comps[c])
                    if (!is_bad[node])
                        ++fin_ans;
            } else {
                ++fin_ans;
                mark(c);
            }
        }
        visit[c] = true;

        for (int v : dag[c]) {
            if (--in_deg[v] == 0) {
                if (bad_comp[v])
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }

    printf("%d\n", fin_ans);

    return 0;
}
