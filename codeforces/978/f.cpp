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

constexpr int MAXN = 200005;
int n, m;
int r[MAXN];
int bad[MAXN];
int ids[MAXN];
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &r[i]);
        ids[i] = i;
    }

    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf(" %d %d", &u, &v);
        if (r[u] < r[v]) {
            bad[v]++;
        } else if (r[v] < r[u]) {
            bad[u]++;
        }
    }
    sort(ids + 1, ids + n + 1, [](int a, int b) {
        return r[a] < r[b];
    });

    int j = 1;
    for (int i = 1; i <= n; ++i) {
        while (r[ids[j]] != r[ids[i]]) ++j;
        ans[ids[i]] = j - 1 - bad[ids[i]];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
