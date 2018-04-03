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

constexpr int MAXN = 100005;
int n, k, m;
int costs[MAXN];
string words[MAXN];
map<string, int> lookup;
int uf[MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;

    uf[xr] = yr;
    costs[yr] = min(costs[yr], costs[xr]);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        lookup[words[i]] = i;
        uf[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    int x, y;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        int last = -1;
        for (int j = 0; j < x; ++j) {
            cin >> y;
            --y;
            if (j) {
                merge(last, y);
            }
            last = y;
        }
    }

    ll ans = 0LL;
    string word;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        int idx = lookup[word];
        ans = ans + costs[find(idx)];
    }

    cout << ans << '\n';

    return 0;
}
