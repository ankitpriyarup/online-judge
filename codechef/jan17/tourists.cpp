#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int num_cities, num_edges;

// (neighbor, index into edges)
vector<pair<int, int> > tree[100005];
int edges[200005][2];
bool flip[200005];
bool visit[200005];

void conn_dfs(int node) {
    for (pair<int, int> edge : tree[node]) {
        if (!visit[edge.first]) {
            visit[edge.first] = true;
            conn_dfs(edge.first);
        }
    }
}

void dfs(int node) {
    while (!tree[node].empty()) {
        pair<int, int> edge = tree[node].back();
        tree[node].pop_back();
        int neighbor = edge.first;

        for (int i = 0; i < tree[neighbor].size(); ++i) {
            if (tree[neighbor][i].first == node) {
                tree[neighbor].erase(tree[neighbor].begin() + i);
                break;
            }
        }

        if (edges[edge.second][1] == node) {
            flip[edge.second] = true;
        }

        dfs(neighbor);
    }
}

int main() {
    cin >> num_cities >> num_edges;

    int a, b;
    for (int i = 0; i < num_edges; ++i) {
        cin >> a >> b;
        tree[a].push_back(make_pair(b, i));
        tree[b].push_back(make_pair(a, i));

        edges[i][0] = a;
        edges[i][1] = b;
    }

    bool all_even_degree = true;
    bool connected = true;

    visit[1] = true;
    conn_dfs(1);

    for (int i = 1; i <= num_cities; ++i) {
        all_even_degree &= (tree[i].size() % 2 == 0);
        connected &= visit[i];
    }

    if (!all_even_degree or !connected) {
        cout << "NO\n";
    } else {
        memset(flip, false, sizeof(flip));

        for (int i = 1; i <= num_cities; ++i) {
            dfs(i);
        }

        cout << "YES\n";
        for (int i = 0; i < num_edges; ++i) {
            if (flip[i]) {
                cout << edges[i][1] << ' ' << edges[i][0] << '\n';
            } else {
                cout << edges[i][0] << ' ' << edges[i][1] << '\n';
            }
        }
    }

    return 0;
}
