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

int a[102][102];
int uf[102];
int find(int x) {
    return uf[x] == x ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return false;
    uf[yr] = xr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, k;
    scanf(" %d %d %d", &m, &n, &k);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    // ensure every client can map to a facility
    for (int i = 0; i < n; ++i) {
        bool has_zero = false;
        for (int j = 0; j < m; ++j) {
            has_zero |= (a[j][i] == 0);
        }

        if (!has_zero) {
            printf("no\n");
            return 0;
        }

        uf[i] = i;
    }

    // take any rectangle in the matrix. the sum of any corner <= sum of other 3 corners
    // let the corners be a b c d. Let a = b = 0. Then
    // c <= d
    // d <= c
    // c = d
    //
    // Deduplicate the facilities, deduplicate the clients. See if you can match then?
    int cc = n;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int p = 0; p < m; ++p) {
                if (!a[p][i] and !a[p][j]) {
                    cc -= merge(i, j);
                    break;
                }
            }
        }
    }

    printf("%s\n", cc <= k ? "yes" : "no");

    return 0;
}
