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

constexpr int MAXN = 200005;
int n;
vector<int> graph[MAXN];
bool negated[MAXN];
int dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int src, sink;
    scanf("%d %d %d", &n, &src, &sink);
    int k, x;
    char buf[3];

    set<int> unvisited;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", buf, &k);
        negated[i] = buf[0] == 'C';

        for (int j = 0; j < k; ++j) {
            scanf("%d", &x);
            graph[i].push_back(x);
        }

        sort(begin(graph[i]), end(graph[i]));

        unvisited.insert(i);
    }

    set<int> frontier;
    frontier.insert(src);
    unvisited.erase(src);

    int lvl = 0;
    memset(dist, -1, sizeof(dist));
    bool found = false;
    while (!found and !frontier.empty()) {
        vector<int> pos;
        vector<int> negs;
        for (int x : frontier) {
            dist[x] = lvl;
            if (negated[x])
                negs.push_back(x);
            else
                pos.push_back(x);

            if (x == sink) {
                found = true;
                break;
            }
        }

        if (found) break;

        frontier.clear();

        if (!negs.empty()) {
            // the only things that DON'T become the frontier are the nodes in
            // the intersection
            set<int> held_back(begin(graph[negs[0]]), end(graph[negs[0]]));
            for (int i = 1; i < negs.size(); ++i) {
                vector<int> culled;
                for (int node : held_back) {
                    auto it = lower_bound(begin(graph[negs[i]]), end(graph[negs[i]]), node);
                    if (it == end(graph[negs[i]]) or *it != node) {
                        culled.push_back(node);
                    }
                }

                for (int rem : culled) {
                    held_back.erase(rem);
                }
            }

            for (int x : held_back)
                unvisited.erase(x);

            swap(frontier, unvisited);
            swap(unvisited, held_back);
        }

        // do a normal bfs
        for (int x : pos) {
            for (int dst : graph[x]) {
                auto it = unvisited.find(dst);
                if (it != end(unvisited)) {
                    frontier.insert(dst);
                    unvisited.erase(it);
                }
            }
        }

        ++lvl;
    }

    if (dist[sink] == -1) {
        printf("%s\n", "Impossible");
    } else {
        printf("%d\n", dist[sink]);
    }

    return 0;
}
