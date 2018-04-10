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
using pii = pair<int, ll>;

constexpr int MAXN = 150005;
constexpr ll MAXV = 1e17;
int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    ll x;
    vector<ll> coords;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i] = x;
        while (x < MAXV) {
            coords.push_back(x);
            x *= 2LL;
        }
    }

    sort(begin(coords), end(coords));
    coords.resize(unique(begin(coords), end(coords)) - begin(coords));
    vector<vector<int>> idxs(coords.size());

    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(begin(coords), end(coords), a[i]) - begin(coords);
        idxs[idx].push_back(i);
    }

    for (size_t idx = 0; idx < coords.size(); ++idx) {
        sort(begin(idxs[idx]), end(idxs[idx]));
        int idx2 = lower_bound(begin(coords), end(coords), 2LL * coords[idx]) - begin(coords);
        for (int i = 0; i + 2 <= idxs[idx].size(); i += 2) {
            idxs[idx2].push_back(idxs[idx][i + 1]);
        }
    }

    vector<pii> res;
    for (size_t idx = 0; idx < coords.size(); ++idx) {
        if (idxs[idx].size() % 2 == 1) {
            res.emplace_back(idxs[idx].back(), coords[idx]);
        }
    }

    sort(begin(res), end(res));
    cout << res.size() << '\n';
    for (const auto& p : res) {
        cout << p.second << ' ';
    }

    return 0;
}
