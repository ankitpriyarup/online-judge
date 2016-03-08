#include <iostream>
#include <vector>

using namespace std;

vector<int> children[100005];
bool cats[100005];

int N, M;
int ans = 0;

void dfs(int node, int parent, int cats_seen) {
    bool leaf = true;
    if (cats_seen > M) {
        return;
    }

    for (auto it = children[node].begin(); it != children[node].end(); ++it) {
        if (*it != parent) {
            leaf = false;
            dfs(*it, node, cats[*it] ? cats_seen + cats[*it] : 0);
        }
    }

    if (leaf) {
        ans++;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> cats[i];
    }

    int x, y;
    for (int i = 0; i < N - 1; ++i) {
        cin >> x >> y;
        x--; y--;
        children[x].push_back(y);
        children[y].push_back(x);
    }
    
    dfs(0, -1, cats[0]);

    cout << ans << '\n';
    return 0;
}
