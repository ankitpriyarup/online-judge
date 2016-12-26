#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std; 

int n, m, q;

vector<pair<int, long long> > tree[100005];
long long dist[100005];
int parent[100005];
vector<int> component;

void dfs(int node, int p, long long d) {
    component.push_back(node);
    dist[node] = d;
    parent[node] = p;
    for (pair<int, long long> edge : tree[node]) {
        int child = edge.first;
        long long cost = edge.second;
        if (child != parent[node]) {
            dfs(child, node, d + cost);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    int u, v, l;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> l;
        --u;
        --v;

        tree[u].push_back(make_pair(v, l));
        tree[v].push_back(make_pair(u, l));
    }

    memset(dist, -1, sizeof(dist));
    long long ans = 0LL;
    vector<long long> heights;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == -1) {
            component.clear();
            dfs(i, -1, 0LL);

            long long furthest = 0LL;
            int diam1 = i;
            for (int j : component) {
                if (dist[j] > furthest) {
                    furthest = dist[j];
                    diam1 = j;
                }
            }

            component.clear();
            dfs(diam1, -1, 0LL);
            furthest = 0;
            int diam2 = i;
            for (int j : component) {
                if (dist[j] > furthest) {
                    furthest = dist[j];
                    diam2 = j;
                }
            }

            if (q == 1) {
                ans += (furthest + 1);
            } else {
                long long dist0 = 0LL;
                long long dist1 = furthest;
                long long best_height = furthest;
                while (dist0 < dist1) {
                    for (pair<int, long long> edge : tree[diam2]) {
                        if (edge.first == parent[diam2]) {
                            dist0 += edge.second;
                            dist1 -= edge.second;
                            diam2 = parent[diam2];
                            best_height = min(best_height, max(dist0, dist1));
                            break;
                        }
                    }
                }

                heights.push_back(best_height);
            }
        }
    }

    if (q == 1) {
        ans -= 1;
        cout << ans << '\n';
    } else {
        long long min_height = 0;
        for (long long height : heights) {
            if (min_height == height) {
                ++min_height;
            } else {
                min_height = max(min_height, height);
            }
        }

        cout << min_height << '\n';
    }

    return 0;
}
