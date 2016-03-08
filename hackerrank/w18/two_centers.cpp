#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> adjlist[5005];
int dists[5005][5005];

void dfs(int start, int node, int parent, int dist) {
    dists[start][node] = dist;
    dists[node][start] = dist;

    for (auto it = adjlist[node].begin(); it != adjlist[node].end(); ++it) {
        if (*it == parent) continue;
        dfs(start, *it, node, dist + 1);
    }
}

int main() {
    cin >> N;

    int x, y;
    for (int i = 0; i < N - 1; ++i) {
        cin >> x >> y;
        x--; y--;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    for (int i = 0; i < N; ++i) {
        dfs(i, i, -1, 0);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

        }
    }

    return 0;
}
