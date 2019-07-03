#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    queue<pii> q;
    set<pii> vis;
    set<pii> bad;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        q.emplace(x, y);
        vis.emplace(x, y);
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        bad.emplace(x, y);
        auto it = vis.find({x, y});
        if (it != end(vis))
            vis.erase(it);
    }

    for (int lvl = 0; lvl < t; ++lvl) {
        int qsz = q.size();
        while (qsz-- > 0) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            if (bad.count({x, y}))
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (vis.count({nx, ny}) or bad.count({nx, ny}))
                    continue;

                vis.emplace(nx, ny);
                q.emplace(nx, ny);
            }
        }
    }

    cout << vis.size() << '\n';
    
    return 0;
}
