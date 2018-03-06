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

constexpr int MAXN = 100005;
int n, m;
int p[MAXN];

int patience[MAXN];
int dpup[MAXN];
int dpdown[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int l, r;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &r);
        ++p[l];
        --p[r + 1];
    }

    for (int i = 1; i <= m; ++i) {
        p[i] += p[i - 1];
    }

    // 1 1 1 1

    //       v
    // 1 2 2 1 2 2
    //
    // ..LIS??? longest mountain type sequence
    /*
    for (int i = 1; i <= m; ++i) {
        printf("%d%c", p[i], " \n"[i == m]);
    }
    */

    dpup[1] = 1;
    patience[1] = p[1];
    int up = 1;
    for (int i = 2; i <= m; ++i) {
        if (p[i] >= patience[up]) {
            patience[++up] = p[i];
            dpup[i] = up;
        } else {
            // find the largest i such that patience[i] <= p[i]
            int lo = 1;
            int hi = up;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (patience[mid] <= p[i]) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            dpup[i] = hi;
            patience[hi] = p[i];
        }

        // printf("LIS(%d) = %d\n", i, dpup[i]);
    }

    dpdown[m] = 1;
    patience[1] = p[m];
    int down = 1;
    for (int i = m - 1; i >= 1; --i) {
        if (p[i] < patience[1]) {
            patience[1] = p[i];
            dpdown[i] = 1;
        } else if (p[i] >= patience[down]) {
            patience[++down] = p[i];
            dpdown[i] = down;
        } else {
            // find the largest i such that patience[i] <= p[i]
            int lo = 1;
            int hi = down;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                if (patience[mid] > p[i]) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            dpdown[i] = hi;
            patience[hi] = p[i];
        }

        // printf("LDS(%d) = %d\n", i, dpdown[i]);
    }

    int ans = max(dpup[m], dpdown[1]);
    for (int i = 1; i < m; ++i) {
        ans = max(ans, dpup[i] + dpdown[i + 1]);
    }

    printf("%d\n", ans);

    return 0;
}
