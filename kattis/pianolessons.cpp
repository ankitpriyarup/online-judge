#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool find(const vector<vi>& graph, vi& match, vector<bool>& seen, int j) {
    if (match[j] == -1) return true;

    seen[j] = true;
    int di = match[j];
    for (auto& e : graph[di]) {
        if (!seen[e] and find(graph, match, seen, e)) {
            match[e] = di;
            return true;
        }
    }

    return false;
}

int dfs_matching(const vector<vi>& graph, int n, int m) {
    vector<int> match;
    vector<bool> seen;
    match.assign(m, -1);
    for (int i = 0; i < n; ++i) {
        seen.assign(m, 0);
        for (auto& j : graph[i]) {
            if (find(graph, match, seen, j)) {
                match[j] = i;
                break;
            }
        }
    }

    return m - count(begin(match), end(match), -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    mt19937 rng((uint64_t) new char);

    int n, m;
    cin >> n >> m;
    vector<vi> graph(n);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        graph[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> graph[i][j];
            --graph[i][j];
        }
        shuffle(all(graph[i]), rng);
    }

    cout << dfs_matching(graph, n, m) << '\n';

    return 0;
}
