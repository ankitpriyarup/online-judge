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

int h, w, n, m;
int a[25][25];
int b[25][25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d", &h, &w, &n, &m);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i + n <= h; ++i) {
        for (int j = 0; j + m <= w; ++j) {
            ll ret = 0;
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    ret += 1LL * b[k][l] * a[i + k][j + l];
                }
            }

            printf("%lld ", ret);
        }
        printf("\n");
    }
    return 0;
}
