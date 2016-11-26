#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e7;
int n;

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

vector<pair<int, int> > graph[1005];
int aug[1005];
int previous[1005];

int ind(int x, int y, int z) {
    return 10 * 10 * x + 10 * y + z;
}

bool in_bounds(int x, int y, int z) {
    return 0 <= x && x < 10
       and 0 <= y && y < 10
       and 0 <= z && z < 10;
}

bool bfs(int source, int sink) {
    memset(aug, -1, sizeof(aug));
    memset(previous, -1, sizeof(previous));
    aug[source] = INF;

    bool found = false;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        found |= (cur == sink);

        for (pair<int, int> edge : graph[cur]) {
            int next_pos = edge.first;
            int cap = edge.second;
            if (cap > 0 and aug[next_pos] == -1) {
                aug[next_pos] = min(aug[cur], cap);
                previous[next_pos] = cur;
                q.push(next_pos);
            }
        }
    }

    return found;
}

int max_flow(int source, int sink) {
    int ans = 0;
    while (bfs(source, sink)) {
        int min_edge = aug[sink];
        ans += min_edge;

        //cout << "Found path of capacity " << min_edge << '\n';
        int node = sink;

        while (node != source) {
            int parent = previous[node];
            bool found = false;
            for (int i = 0; i < graph[parent].size(); ++i) {
                if (graph[parent][i].first == node) {
                    graph[parent][i].second -= min_edge;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cerr << "BAD: COULD NOT FIND EDGE FROM " << parent << " to " << node << '\n';
            }
            
            found = false;
            for (int i = 0; i < graph[node].size(); ++i) {
                if (graph[node][i].first == parent) {
                    graph[node][i].second += min_edge;
                    break;
                }
            }

            if (!found) {
                graph[node].push_back(make_pair(parent, min_edge));
            }

            //cout << "node " << node << '\n';
            node = parent;
        }
    }

    return ans;
}

int main() {
    int T, x, y, z;
    cin >> T;

    int source = 10 * 10 * 10 + 1;
    int sink = 10 * 10 * 10 + 2;

    while (T-- > 0) {
        for (int i = 0; i <= sink; ++i) {
            graph[i].clear();
        }
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> z;
            graph[source].push_back(make_pair(ind(x, y, z), INF));
            //cout << source << ' ' << ind(x, y, z) << ' ' << INF << '\n';
        }

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int d = 0; d < 6; ++d) {
                        x = i + dx[d];
                        y = j + dy[d];
                        z = k + dz[d];
                        if (in_bounds(x, y, z)) {
                            graph[ind(i, j, k)].push_back(make_pair(ind(x, y, z), 1));

                            //cout << ind(i, j, k) << ' ' << ind(x, y, z) << ' ' << 1 << '\n';
                        }
                    }

                    int sink_cost = (i == 0 or i == 9) + (j == 0 or j == 9) + (k == 0 or k == 9);

                    if (sink_cost > 0) {
                        graph[ind(i, j, k)].push_back(make_pair(sink, sink_cost));
                        //cout << ind(i, j, k) << ' ' << sink << ' ' << sink_cost << '\n';
                    }
                }
            }
        }

        cout << max_flow(source, sink) << '\n';
    }
}
