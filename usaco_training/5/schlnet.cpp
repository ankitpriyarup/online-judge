/*
USER: rednano1
PROG: schlnet
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <bitset>

using namespace std;

constexpr int MAXN = 103;
int n;
vector<int> graph[MAXN];
vector<int> dag[MAXN];
vector<int> val, comp, cont, z;
int in_deg[MAXN];
int out_deg[MAXN];
int timer, ncomps; 

int dfs(int node) {
    int low = val[node] = ++timer, x;
    z.push_back(node);

    for (auto e : graph[node]) {
        if (comp[e] < 0) {
            low = min(low, val[e] ? : dfs(e));
        }
    }

    if (low == val[node]) {
        // printf("New comp:");
        do {
            x = z.back(); z.pop_back();
            // printf(" %d", x);
            comp[x] = ncomps;
        } while (x != node);
        // printf("\n");

        ++ncomps;
    }

    return val[node] = low;
}

int main() {
    freopen("schlnet.in", "r", stdin);
    freopen("schlnet.out", "w", stdout);

    scanf("%d", &n);
    // printf("n is %d\n", n);
    int x;
    for (int i = 1; i <= n; ++i) {
        while (true) {
            scanf("%d", &x);
            if (x == 0) break;

            graph[i - 1].push_back(x - 1);
        }
    }

    // find the strongly connected components to make a dag
    // answer to subtask A is the number of "DAG roots" (SCC's without parents)
    val.assign(n, 0);
    comp.assign(n, -1);

    timer = ncomps = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] < 0) {
            // printf("Starting dfs from %d\n", i);
            dfs(i);
        } else {
            // printf("Not running from node %d because comp is %d\n", i, comp[i]);
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (comp[u] != comp[v]) {
                if (find(begin(dag[comp[u]]), end(dag[comp[u]]), comp[v]) == end(dag[comp[u]])) {
                    dag[comp[u]].push_back(comp[v]);
                    ++in_deg[comp[v]];
                    ++out_deg[comp[u]];
                }
            }
        }
    }

    int ans_a = ncomps;
    int ans_b = ncomps;
    for (int i = 0; i < ncomps; ++i) {
        if (in_deg[i] != 0)
            --ans_a;

        if (out_deg[i] != 0)
            --ans_b;
    }

    if (ncomps == 1)
        printf("%d\n%d\n", ans_a, 0);
    else
        printf("%d\n%d\n", ans_a, max(ans_a, ans_b));

    return 0;
}
