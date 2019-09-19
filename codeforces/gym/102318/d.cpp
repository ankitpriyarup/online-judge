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

    vi dx = {1, 0, -1, 0};
    vi dy = {0, -1, 0, 1};

    int T;
    cin >> T;
    while (T-- > 0) {
        int f;
        cin >> f;
        vi s(f);
        for (auto& si : s) {
            cin >> si;
        }

        int rc, cc, rm, cm;
        cin >> rc >> cc;
        cin >> rm >> cm;

        --rc; --rm;

        queue<pii> q;
        map<pii, int> dist;
        dist[{rc, cc}] = 0;
        q.emplace(rc, cc);

        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            assert(0 <= y and y <= s[x]);
            // cout << x << ' ' << y << ' ' << dist[{x, y}] << '\n';
            
            vector<pii> nxts;

            if (x > 0) {
                nxts.emplace_back(x - 1, min(y, s[x - 1]));
            }
            if (x + 1 < f) {
                nxts.emplace_back(x + 1, min(y, s[x + 1]));
            }
            if (!(x == 0 and y == 0)) {
                if (y == 0) {
                    nxts.emplace_back(x - 1, s[x - 1]);
                } else {
                    nxts.emplace_back(x, y - 1);
                }
            }

            if (!(x == f - 1 and y == s[f - 1])) {
                if (y == s[x]) {
                    nxts.emplace_back(x + 1, 0);
                } else {
                    nxts.emplace_back(x, y + 1);
                }
            }

            for (auto& p : nxts) {
                if (dist.find(p) == end(dist)) {
                    dist[p] = dist[{x, y}] + 1;
                    q.push(p);
                }
            }
        }

        cout << dist[{rm, cm}] << '\n';
    }
    
    return 0;
}
