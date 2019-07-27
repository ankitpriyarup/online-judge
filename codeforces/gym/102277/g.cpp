#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool between(const vector<pii>& players, int a, int b, int c) {
    ll v1x = players[b].first - players[a].first;
    ll v1y = players[b].second - players[a].second;

    ll v2x = players[c].first - players[a].first;
    ll v2y = players[c].second - players[a].second;

    ll cross = v1x * v2y - v1y * v2x;

    ll v1d = v1x * v1x + v1y * v1y;
    ll v2d = v2x * v2x + v2y * v2y;

    ll dot = v1x * v2x + v1y * v2y;

    return cross == 0 and v2d < v1d and dot > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pii> players(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> players[i].first >> players[i].second;
    }

    vector<vi> graph(2 * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            int mid = -1;

            for (int k = 0; mid > -2 and k < 2 * n; ++k) {
                if (k == i or k == j) continue;

                if (between(players, i, j, k))  {
                    if (mid == -1) {
                        mid = k;
                        break;
                    } else {
                        mid = -2;
                        break;
                    }
                }
            }

            if (mid == -1/* or (0 <= mid and mid < n)*/) {
                //cout << i << " -> " << j << '\n';
                graph[i].push_back(j);
            }
        }
    }

    vi dist(n, 3e5);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[n - 1] > n) {
        cout << "-1\n";
    } else {
        cout << dist[n - 1] << '\n';
    }

    return 0;
}
