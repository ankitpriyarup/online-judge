#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX_N 100005
#define MOD 1000000007

using namespace std;

int N, M; // Number of vertices and edges respectively
int dfs_num[MAX_N]; // The DFS number of a vertex
int dfs_low[MAX_N]; // The DFS low number of a vertex
int dfs_index = 0; // The next available DFS number 
bool in_stack[MAX_N]; // A bit to see if a node is in the stack

vector<int> graph[MAX_N]; // The graph
stack<int> component_stack; // The stack containing the current component

int cost[MAX_N]; // Cost to use a vertex, unneccessary for Tarjan's
long long ans = 0LL; // Minimum cost needed to fill guard posts
long long ways = 1LL; // Number of ways to fill guard posts

void dfs(int node) {
    dfs_num[node] = dfs_index;
    dfs_low[node] = dfs_index;
    dfs_index++;

    component_stack.push(node);
    in_stack[node] = true;

    for (auto it = graph[node].begin(); it != graph[node].end(); it++) {
        if (dfs_num[*it] == -1) {
            dfs(*it);
            dfs_low[node] = min(dfs_low[node], dfs_low[*it]);
        } else if (in_stack[*it]) {
            dfs_low[node] = min(dfs_low[node], dfs_num[*it]);
        }
    }

    if (dfs_num[node] == dfs_low[node]) {
        // found a strongly connected component
        int low_cost = 1e9;
        int low_count = 0;
        int w;
        do {
            w = component_stack.top();
            component_stack.pop();
            in_stack[w] = false;
            // add to current SCC
            if (cost[w] < low_cost) {
                low_cost = cost[w];
                low_count = 0;
            }

            if (cost[w] == low_cost) {
                low_count++;
            }
        } while (w != node);
        // SCC done
        //cout << "DEBUG: " << low_cost << " " << low_count << '\n';
        ans += low_cost;
        ways *= low_count;
        ways %= MOD;
    }
}

int main() {
    cin >> N;
    memset(dfs_num, -1, sizeof dfs_num);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    cin >> M;
    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        if (dfs_num[i] == -1) {
            dfs(i);
        }
    }

    cout << ans << " " << ways << '\n';
    return 0;
}
