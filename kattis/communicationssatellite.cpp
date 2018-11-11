#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;

using dish = tuple<int, int, int>;
using state = tuple<double, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y, r;
    cin >> n;
    vector<dish> dishes;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r; 
        dishes.emplace_back(x, y, r);
    }

    vector<bool> vis(n, false);
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0.0, 0);

    double ans = 0.0;
    double w;
    int u;
    while (!pq.empty()) {
        tie(w, u) = pq.top();
        pq.pop();
        if (vis[u]) {
            continue;
        }

        int ux, uy, ur;
        tie(ux, uy, ur) = dishes[u];

        vis[u] = true;
        ans += w;
        for (int v = 0; v < n; ++v) {
            if (vis[v]) {
                continue;
            }
            
            int vx, vy, vr;
            tie(vx, vy, vr) = dishes[v];

            int dx = ux - vx;
            int dy = uy - vy;

            double weight = sqrt(dx * dx + dy * dy) - ur - vr;
            pq.emplace(weight, v);
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}
