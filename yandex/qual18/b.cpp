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

constexpr int MAXN = 404;
int n;
int frag[MAXN][MAXN];
bool seen[MAXN * MAXN];
int mat[MAXN][MAXN];
int col[MAXN * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int start = -1;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &frag[i][j]);
        }

        if (seen[frag[i][0]])
            start = i;
        seen[frag[i][0]] = true;
    }

    assert(start != -1);

    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; ++i) {
        mat[0][i] = frag[start][i];
        col[mat[0][i]] = i;
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (col[frag[i][0]] == -1) continue;
        if (i == start) continue;

        for (int j = 0; j < n; ++j) {
            mat[j][col[frag[i][0]]] = frag[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d%c", mat[i][j], " \n"[i == n - 1 and j == n - 1]);
        }
    }

    return 0;
}
