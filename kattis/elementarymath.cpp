#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
const int MAXN = 2503;
const int MAX_NODES = 5 * MAXN;

int n;
int input[MAXN][2];
long long values[MAX_NODES];

map<ll, int> to_id;
int next_id;

set<int> graph[MAX_NODES];
bool visit[MAX_NODES];
int previous[MAX_NODES];

char out[MAXN][100];

bool bfs(int source, int sink) {
    queue<int> q;
    q.push(source);

    memset(visit, 0, sizeof(visit));
    memset(previous, -1, sizeof(previous));
    visit[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == sink) {
            return true;
        }

        for (int next_node : graph[node]) {
            if (!visit[next_node]) {
                visit[next_node] = true;
                previous[next_node] = node;
                q.push(next_node);
            }
        }
    }

    return false;
}

void augment(int source, int sink) {
    int cur = sink;
    while (cur != source) {
        int prev_node = previous[cur];
        graph[prev_node].erase(cur);
        graph[cur].insert(prev_node);

        cur = prev_node;
    }
}

bool max_flow(int source, int sink) {
    for (int i = 0; i < n; ++i) {
        if (bfs(source, sink)) {
            augment(source, sink);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    scanf("%d", &n);
    next_id = n;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &input[i][0], &input[i][1]);

        long long option = input[i][0] + input[i][1];
        if (to_id.find(option) == to_id.end()) {
            values[next_id] = option;
            to_id[option] = next_id;
            ++next_id;
        }

        graph[i].insert(to_id[option]);

        option = input[i][0] - input[i][1];
        if (to_id.find(option) == to_id.end()) {
            values[next_id] = option;
            to_id[option] = next_id;
            ++next_id;
        }

        graph[i].insert(to_id[option]);

        option = 1LL * input[i][0] * input[i][1];
        if (to_id.find(option) == to_id.end()) {
            values[next_id] = option;
            to_id[option] = next_id;
            ++next_id;
        }

        graph[i].insert(to_id[option]);
    }

    int source = next_id++;
    int sink = next_id++;
    // connect source to all the pairs
    for (int i = 0; i < n; ++i) {
        graph[source].insert(i);
    }

    // connect sink to all the ends
    for (int i = n; i < source; ++i) {
        graph[i].insert(sink);
    }

    bool valid = max_flow(source, sink);

    if (valid) {
        for (int node : graph[sink]) {
            long long ans = values[node];
            assert(graph[node].size() == 1);
            int ind = *(graph[node].begin());

            char op = '+';
            if (input[ind][0] - input[ind][1] == ans) {
                op = '-';
            } else if (1LL * input[ind][0] * input[ind][1] == ans) {
                op = '*';
            }

            sprintf(out[ind], "%d %c %d = %lld", input[ind][0], op, input[ind][1], ans);
        }

        for (int i = 0; i < n; ++i) {
            printf("%s\n", out[i]);
        }
    } else {
        puts("impossible");
    }

    return 0;
}
