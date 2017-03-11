#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 32;
const int INF = 1e8;

int b, h;
int n, m;
char grid[MAXN][MAXN];
long double lit[MAXN][MAXN];
bool safe[MAXN][MAXN];

vector<pair<int, int> > graph[MAXN * MAXN];
int previous[MAXN * MAXN];
int aug[MAXN * MAXN];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

inline int coord(const int& x, const int& y) {
    return x * m + y;
}

inline bool in_bounds(const int& x, const int& y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

void read() {
    scanf("%d", &b);
    scanf("%d", &h);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }
}

void illuminate() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    // (i, j) -> (k, l)
                    int dx = k - i;
                    int dy = l - j;

                    long double illum = (grid[i][j] - '0') / (0.0L + dx * dx + dy * dy + h * h);
                    lit[k][l] += illum;
                }
            }
        }
    }
}

void build_graph(int source, int sink) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool bright = lit[i][j] >= b;
            int idx1 = coord(i, j);

            if (!bright) {
                graph[idx1].push_back(make_pair(sink, INF));
            }

            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                int idx2 = coord(nx, ny);

                if (in_bounds(nx, ny)) {
                    int cost = (bright and lit[nx][ny] >= b) ? 43 : 11;
                    graph[idx1].push_back(make_pair(idx2, cost));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        graph[source].push_back(make_pair(coord(i, 0), INF));
        graph[source].push_back(make_pair(coord(i, m - 1), INF));
    }
    for (int j = 1; j < m - 1; ++j) {
        graph[source].push_back(make_pair(coord(0, j), INF));
        graph[source].push_back(make_pair(coord(n - 1, j), INF));
    }
}


bool bfs(int source, int sink) {
    memset(previous, -1, sizeof(previous));
    memset(aug, -1, sizeof(aug));
    queue<int> q;
    q.push(source);
    aug[source] = INF;

    bool found = false;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        found |= (cur == sink);

        for (pair<int, int> edge : graph[cur]) {
            int next_pos = edge.first;
            int cap = edge.second;

            if (cap > 0 && previous[next_pos] == -1) {
                q.push(next_pos);
                previous[next_pos] = cur;
                aug[next_pos] = min(aug[cur], cap);
            }
        }
    }

    return found;
}

int max_flow(int source, int sink) {
    int ans = 0;
    while (bfs(source, sink)) {
        int min_edge = aug[sink];

        int node = sink;
        while (node != source) {
            for (int i = 0; i < graph[previous[node]].size(); ++i) {
                if (graph[previous[node]][i].first == node) {
                    graph[previous[node]][i].second -= min_edge;    
                }
            }

            for (int i = 0; i < graph[node].size(); ++i) {
                if (graph[node][i].first == previous[node]) {
                    graph[node][i].second += min_edge;    
                }
            }

            node = previous[node];
        }

        ans += min_edge;
    }

    return ans;
}

int main() {
    read();
    illuminate();

    int source = n * m;
    int sink = n * m + 1;

    build_graph(source, sink);

    int ans = max_flow(source, sink);

    printf("%d\n", ans);
    return 0;
}
