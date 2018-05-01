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

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

pii find(map<pii, pair<pii, pii>>& uf, const pii& p) {
    if (uf[p].first == p)
        return p;

    return uf[p].first = find(uf, uf[p].first);
}

bool merge(map<pii, pair<pii, pii>>& uf, const pii& p0, const pii& p1) {
    pii xr = find(uf, p0);
    pii yr = find(uf, p1);

    if (xr == yr) {
        uf[xr].second.second += 1;
        if (uf[xr].second.first == uf[xr].second.second)
            return true;

        return false;
    }

    uf[yr].second.first += uf[xr].second.first;
    uf[yr].second.second += uf[xr].second.second + 1;
    uf[xr] = {yr, {0, 0}};

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    scanf(" %d", &m);
    int a, b, c, d;
    vector<pair<pii, pii>> edges;
    map<pii, pair<pii, pii> > uf;
    for (int i = 1; i <= m; ++i) {
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        pii p0 = {a, b};
        pii p1 = {c, d};
        edges.emplace_back(p0, p1);
        uf[p0] = {p0, {1, 0}};
        uf[p1] = {p1, {1, 0}};
    }

    for (int i = 0; i < m; ++i) {
        if (merge(uf, edges[i].first, edges[i].second))
            return printf("%d\n", i + 1), 0;
    }
    
    printf("%d\n", 0);
    return 0;
}
