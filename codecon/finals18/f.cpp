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

constexpr int MAXL = 100;
using player = tuple<ll, ll, ll>;
int L;
int x[MAXL], y[MAXL];
int off[5][2];
int def[5][2];
int ball[2];
int furthest[50];

ll dist(int x1, int y1, int x2, int y2) {
    ll xd = x2 - x1;
    ll yd = y2 - y1;

    return xd * xd + yd * yd;
}

int main() {
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> x[i] >> y[i];
        furthest[x[i]] = max(furthest[x[i]], y[i] + 1);
    }

    for (int i = 0; i < 5; ++i) {
        cin >> off[i][0] >> off[i][1];
    }
    
    for (int i = 0; i < 5; ++i) {
        cin >> def[i][0] >> def[i][1];
    }

    cin >> ball[0] >> ball[1];

    vector<player> res;
    for (int i = 0; i < 5; ++i) {
        if (off[i][1] < furthest[off[i][0]]) {
            continue;
        }

        ll def_dist = 1e18;
        for (int j = 0; j < 5; ++j) {
            def_dist = min(def_dist, dist(off[i][0], off[i][1], def[j][0], def[j][1]));
        }
        ll ball_dist = dist(off[i][0], off[i][1], ball[0], ball[1]);
        res.push_back(make_tuple(-def_dist, ball_dist, i));
        // cout << def_dist << " " << ball_dist << " " << i << '\n';
    }

    sort(begin(res), end(res));

    bool first = true;
    vector<pii> out;
    for (auto& p : res) {
        if (get<0>(p) != get<0>(res[0]) or get<1>(p) != get<1>(res[0])) continue;
        int x = get<2>(p);
        out.push_back({off[x][0], off[x][1]});
    }

    sort(out.begin(), out.end());
    for (auto& p : out) {
        if (!first) cout << ' ';
        cout << p.first << ' ' << p.second;
        first = false;
    }

    cout << '\n';
    return 0;
}
