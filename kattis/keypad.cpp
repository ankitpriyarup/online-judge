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

constexpr int MAXN = 15;
int n, m;
char grid[MAXN][MAXN];
char out[MAXN][MAXN];

void solve() {
    scanf(" %d %d", &n, &m);
    memset(out, '\0', sizeof(out));
    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);

        for (int j = 0; j < m; ++j) {
            out[i][j] = "NP"[grid[i][j] - '0'];
        }
    }

    for (int i1 = 0; i1 < n; ++i1) {
        for (int j1 = 0; j1 < m; ++j1) {
            if (grid[i1][j1] != '1')
                continue;

            for (int i2 = i1 + 1; i2 < n; ++i2) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (j1 == j2 or grid[i2][j2] != '1') {
                        continue;
                    }

                    if (grid[i1][j2] == '0' or grid[i2][j1] == '0') {
                        printf("impossible\n");
                        return;
                    }

                    out[i1][j1] = out[i2][j2] = out[i1][j2] = out[i2][j1] = 'I';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s\n", out[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        solve();
        printf("----------\n");
    }
    return 0;
}
