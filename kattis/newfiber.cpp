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

constexpr int MAXN = 10004;
int n, m;
int deg[MAXN];
int ids[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        ids[i] = i;
    int u, v;
    int total_deg = 0;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        ++deg[u];
        ++deg[v];
        total_deg += 2;
    }

    int change = 0;
    sort(ids, ids + n, [&](int a, int b) {
        return deg[a] < deg[b];
    });
    reverse(ids, ids + n);
    for (int i = 0; i < n; ++i) {
        if (total_deg == 2 * (n - 1)) break;
        int rem = min(deg[ids[i]] - 1, total_deg - 2 * (n - 1));
        deg[ids[i]] -= rem;
        total_deg -= rem;
        ++change;
    }
    sort(ids, ids + n, [&](int a, int b) {
        return deg[a] < deg[b];
    });
    reverse(ids, ids + n);

    printf("%d\n", change);
    printf("%d %d\n", n, n - 1);
    int ptr = 0;
    for (int i = 1; i < n; ++i) {
        while (deg[ids[ptr]] == 0)
            ++ptr;
        printf("%d %d\n", ids[ptr], ids[i]);
        --deg[ids[ptr]];
        --deg[ids[i]];
    }

    return 0;
}
