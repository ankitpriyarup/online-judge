#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> names(n);
    map<string, int> inv;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        inv[names[i]] = i;
    }

    string junk, name, line_str;
    int k;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> junk >> k;
        getline(cin, line_str);
        for (int j = 0; j < k; ++j) {
            getline(cin, line_str);
            istringstream iss(line_str);
            iss >> junk;
            while (iss >> name) {
                while (name.back() == ',')
                    name.pop_back();

                int dst = inv[name];
                adj[i][dst] = true;
            }
        }
    }

    constexpr int INF = 1e9 + 7;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> back(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        for (int j = 0; j < n; ++j) {
            if (adj[i][j]) {
                dist[i][j] = 1;
                back[i][j] = i;
                q.push(j);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (adj[u][v] and dist[i][v] == INF) {
                    dist[i][v] = dist[i][u] + 1;
                    back[i][v] = u;
                    q.push(v);
                }
            }
        }
    }

    int min_cycle = INF;
    int src = -1;
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < min_cycle) {
            src = i;
            min_cycle = dist[i][i];
        }
    }

    if (src == -1) {
        cout << "SHIP IT\n";
        return 0;
    }

    vector<int> path = {src};
    do {
        path.push_back(back[src][path.back()]);
    } while (path.back() != src);

    reverse(begin(path), end(path));
    path.pop_back();
    for (auto& x : path) {
        cout << names[x] << ' ';
    }

    return 0;
}
