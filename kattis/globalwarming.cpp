#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 202;
const int MAXK = 23;

int n, m;
int dist[MAXN][MAXN];
bool visit[MAXN];

vector<int> graph[MAXN];
long long dp[1 << MAXK];

inline void set(const int& mask, const long long val) {
    dp[mask] = dp[mask] < 0 ? val : min(dp[mask], val);
}

long long solve(const vector<int>& component) {
    int k = component.size();
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for (int mask = 0; mask < (1 << k); ++mask) {
        if (dp[mask] == -1) 
            continue;

        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                continue;
            }

            for (int j = i + 1; j < k; ++j) {
                if (mask & (1 << j)) {
                    continue;
                }

                int new_mask = mask | (1 << i) | (1 << j);
                int edge = dist[component[i]][component[j]];
                set(new_mask, dp[mask] + edge);
            }
        }
    }

    return dp[(1 << k) - 1];
}

int main() {
    scanf("%d %d", &n, &m);
    memset(dist, -1, sizeof(dist));

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    long long ans = 0LL;
    bool impossible = false;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            for (int node : graph[i]) {
                visit[node] = true;
            }
            visit[i] = true;

            graph[i].push_back(i);

            if (graph[i].size() % 2 == 1) {
                impossible = true;
                break;
            }

            ans += solve(graph[i]);
        }
    }

    if (impossible) {
        printf("impossible\n");
    } else {
        printf("%lld\n", ans);
    }

    return 0;
}
