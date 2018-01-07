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

constexpr int MAXN = 1003;
int n, m;
int uf[MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

bool unite(int x, int y) {
    int xp = find(x);
    int yp = find(y);
    if (xp == yp)
        return false;

    uf[xp] = yp;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int u, v;
    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            uf[i] = i;

        int comps = n;
        scanf("%d", &m);

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            comps -= unite(u, v);
        }

        printf("%d\n", comps - 1);
    }

    return 0;
}
