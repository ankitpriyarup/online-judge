#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> games;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            games.emplace_back(i, j);
        }
    }

    int k = games.size();
    vector<vi> graph(k);
    vi in_degree(k, 0);
    vi dp(k, 1);

    for (int i = 0; i < n; ++i) {
        vi a(n - 1);
        for (auto& x : a) {
            cin >> x;
            --x;
        }

        for (int j = 1; j < n - 1; ++j) {
            pii x = a[j - 1] < i ? pii{a[j - 1], i} : pii{i, a[j - 1]};
            pii y = a[j] < i ? pii{a[j], i} : pii{i, a[j]};
            int idx1 = lower_bound(all(games), x) - begin(games);
            int idx2 = lower_bound(all(games), y) - begin(games);

            graph[idx1].push_back(idx2);
            ++in_degree[idx2];
        }
    }

    queue<int> q;
    for (int i = 0; i < k; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int hits = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++hits;

        for (int v : graph[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    /*
    for (int i = 0; i < k; ++i) {
        cout << games[i].first << ' ' << games[i].second << ' ' << dp[i] << '\n';
    }
    */

    if (hits < k) {
        cout << "-1\n";
    } else {
        cout << *max_element(all(dp)) << '\n';
    }
    
    return 0;
}
