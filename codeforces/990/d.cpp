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
int n, a, b;
bool adj[MAXN][MAXN];
int uf[MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return 0;
    uf[xr] = yr;
    return 1;
}

bool check(bool flip) {
    int nc = n;
    for (int i = 0; i < n; ++i)
        uf[i] = i;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (flip ^ adj[i][j])
                nc -= merge(i, j);
        }
    }

    return nc == (flip ? b : a);
}

bool check() {
    return check(true) and check(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d", &n, &a, &b);
    if (a != 1 and b != 1) {
        printf("NO\n");
        return 0;
    }

    bool swapped = false;
    if (a == 1 and b > 1) {
        swap(a, b);
        swapped = true;
    }

    int n_comps = n;
    for (int i = 0; i + 1 < n; ++i) {
        if (n_comps > a) {
            --n_comps;
            adj[i][i + 1] = adj[i + 1][i] = 1;
        }
    }

    if (swapped) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                adj[i][j] ^= 1;
            }
        }

        swap(a, b);
    }

    if (!check()) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
