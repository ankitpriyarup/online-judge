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
using gap = tuple<ll, ll, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> l(n), r(n);
    vector<gap> gaps;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; ++i) {
        ll min_dist = l[i] - r[i - 1];
        ll max_dist = r[i] - l[i - 1];
        gaps.emplace_back(max_dist, min_dist, i);
    }

    set<pair<ll, int>> bridges; 
    ll bridge_len;
    for (int i = 0; i < m; ++i) {
        cin >> bridge_len;
        bridges.emplace(bridge_len, i + 1);
    }

    vector<int> res(n);
    sort(begin(gaps), end(gaps));

    ll lo, hi;
    int idx;
    for (gap& g : gaps) {
        tie(hi, lo, idx) = g;

        auto it = bridges.upper_bound({lo - 1, m + 1});
        if (it == end(bridges) or it->first < lo or it->first > hi) {
            cout << "No\n";
            return 0;
        }

        res[idx] = it->second;
        bridges.erase(it);
    }

    cout << "Yes\n";
    for (int i = 1; i < n; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}
