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

pii intersect(const pii& a, const pii& b) {
    if (a.second <= b.first or b.second <= a.first) {
        return {0, 0};
    }

    return {max(a.first, b.first), min(a.second, b.second)};
}

inline int get_len(const pii& p) {
    return p.second - p.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &a[i].first, &a[i].second);
    }
    vector<pii> prefs(begin(a), end(a));
    vector<pii> suffs(begin(a), end(a));
    for (int i = 1; i < n; ++i) {
        prefs[i] = intersect(prefs[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        suffs[i] = intersect(suffs[i + 1], a[i]);
    }

    int ans = max(get_len(prefs[n - 2]), get_len(suffs[1]));
    for (int i = 1; i + 1 < n; ++i) {
        ans = max(ans, get_len(intersect(prefs[i - 1], suffs[i + 1])));
    }

    printf("%d\n", ans);

    return 0;
}
