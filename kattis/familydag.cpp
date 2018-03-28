#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 222;
using ll = long long;

vector<string> all_names;
vector<pair<string, string>> edges;

void reset() {
    all_names.clear();
    edges.clear();
}

void solve() {
    sort(begin(all_names), end(all_names));
    all_names.erase(unique(begin(all_names), end(all_names)), end(all_names));
    int n = all_names.size();
    vector<vector<int>> graph(n, vector<int>());
    for (const auto& p : edges) {
        int x = lower_bound(begin(all_names), end(all_names), p.first) - begin(all_names);
        int y = lower_bound(begin(all_names), end(all_names), p.second) - begin(all_names);
        graph[y].push_back(x);
    }

    for (int u = 0; u < n; ++u) {
        // check for paradox
        vector<char> vis(n, 0);
        queue<int> q;
        vis[u] = 1;
        q.push(u);
        bool paradox = false;
        bool hilly = false;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : graph[v]) {
                if (vis[w]) {
                    hilly = true;
                    paradox |= (w == u);
                } else {
                    vis[w] = true;
                    q.push(w);
                }
            }
        }
        
        if (paradox) {
            cout << all_names[u] << " paradox" << endl;
        } else if (hilly) {
            cout << all_names[u] << " hillbilly" << endl;
        }
    }
    
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string word, junk, desc;
    while (cin >> word) {
        if (word == "done") {
            solve();
            reset();
            continue;
        }
        
        cin >> junk >> desc;
        all_names.push_back(word);
        all_names.push_back(desc);
        edges.emplace_back(word, desc);
    }
}
