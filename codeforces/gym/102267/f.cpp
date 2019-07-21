#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr ld PI = 3.14159265358979;
constexpr int MAXN = 3003;
constexpr ld EPS = 1e-3;

using fighter = tuple<int, int, int, int>;

int n;
vi graph[MAXN];
int in_deg[MAXN];
fighter people[MAXN];

inline ld norm(ld x) {
    while (x < 0.0)
        x += 2.0 * PI;
    while (x >= 2.0 * PI)
        x -= 2.0 * PI;
    return x;
}

bool in_range(ld x, int lo, int hi) {
    if (lo <= hi) {
        return lo <= x + EPS and x - EPS <= hi;
    } else {
        return lo <= x + EPS or x - EPS <= hi;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, a, r;
        cin >> x >> y >> a >> r;

        people[i] = make_tuple(x, y, (a - r + 360) % 360, (a + r) % 360);
    }

    for (int i = 0; i < n; ++i) {
        int x1, y1, lo, hi;
        tie(x1, y1, lo, hi) = people[i];

        // cout << "Angle range of " << i << " is " << lo << " " << hi << '\n';
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            int x2 = get<0>(people[j]);
            int y2 = get<1>(people[j]);

            ld res = atan2(y2 - y1, x2 - x1);
            if (res < 0.0)
                res += 2.0 * PI;
            res *= 180.0 / PI;
            // cout << "angle of " << j << " is " << res << '\n';

            if (in_range(res, lo, hi)) {
                // cout << (i + 1) << " can see " << (j + 1) << '\n';
                graph[i].push_back(j);
                ++in_deg[j];
            }
        }
    }

    vi ans;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ans.size() != n) {
        cout << -1 << '\n';
    } else {
        for (int x : ans) {
            cout << (x + 1) << ' ';
        }
    }
    
    return 0;
}
