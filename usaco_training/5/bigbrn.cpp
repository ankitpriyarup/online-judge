/*
USER: rednano1
PROG: bigbrn
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <bitset>

using namespace std; 
constexpr int MAXN = 1003;
int n;
int plots[MAXN][MAXN];

bool works(int sz) {
    for (int i = sz; i <= n; ++i) {
        for (int j = sz; j <= n; ++j) {
            int contained = plots[i][j] - plots[i - sz][j] - plots[i][j - sz] + plots[i - sz][j - sz];
            if (contained == 0)
                return true;
        }
    }

    return false;
}

int main() {
    freopen("bigbrn.in", "r", stdin);
    freopen("bigbrn.out", "w", stdout);

    int p, x, y;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d %d", &x, &y);
        ++plots[x][y];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            plots[i][j] += plots[i][j - 1];
        }

        for (int j = 1; j <= n; ++j) {
            plots[i][j] += plots[i - 1][j];
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("%d ", plots[i][j]);
        }
        printf("\n");
    }
    */

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", lo);

    return 0;
}
