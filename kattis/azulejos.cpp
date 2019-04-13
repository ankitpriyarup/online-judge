#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using tile = tuple<int, int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<tile>> tiles(2);
    for (int k = 0; k < 2; ++k) {
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int h;
        for (int i = 0; i < n; ++i) {
            cin >> h;
            tiles[k].emplace_back(p[i], h, i);
        }

        sort(all(tiles[k]));
    }

    constexpr int INF = 1e9 + 7;
    int p0 = 0;
    int p1 = 0;
    set<pii> backs, fronts;
    bool poss = true;
    vector<vi> res(2, vi(n));
    for (int i = 0; i < n; ++i) {
        if (backs.empty()) {
            int back_p = get<0>(tiles[0][p0]);
            int p, h, idx;
            while (p0 < n and get<0>(tiles[0][p0]) == back_p) {
                tie(p, h, idx) = tiles[0][p0];
                // cout << "Enqueue back " << h << ' ' << (idx + 1) << '\n';
                backs.emplace(h, idx);
                ++p0;
            }
        }

        if (fronts.empty()) {
            int front_p = get<0>(tiles[1][p1]);
            int p, h, idx;
            while (p1 < n and get<0>(tiles[1][p1]) == front_p) {
                tie(p, h, idx) = tiles[1][p1];
                // cout << "Enqueue front " << h << ' ' << (idx + 1) << '\n';
                fronts.emplace(h, idx);
                ++p1;
            }
        }

        // find the tallest front piece that is < tallest back piece
        auto tall_boi = make_pair(prev(backs.end())->first, -1);
        auto front_it = fronts.lower_bound(tall_boi);
        if (front_it == begin(fronts)) {
            poss = false;
            break;
        }
        front_it = prev(front_it);
        auto tupp = make_pair(front_it->first, INF);
        auto back_it = backs.upper_bound(tupp);
        if (back_it == end(backs)) {
            poss = false;
            break;
        }

        res[0][i] = back_it->second + 1;
        res[1][i] = front_it->second + 1;
        // cout << "paired back " << res[0][i] << " with front " << res[1][i] << "\n";
        backs.erase(back_it);
        fronts.erase(front_it);
    }

    if (!poss) {
        cout << "impossible\n";
        return 0;
    }

    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            cout << res[k][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
