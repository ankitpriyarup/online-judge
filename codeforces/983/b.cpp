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
using query = tuple<int, int, int>;

constexpr int MAXN = 5003;
constexpr int MAXQ = 100005;
int n, q;
int a[MAXN];
int res[MAXN][MAXN];
int cur[MAXN], cur2[MAXN];
int ans[MAXQ];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
        res[i][1] = a[i];
    }

    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i + j <= n + 1; ++i) {
            res[i][j] = res[i][j - 1] ^ res[i + 1][j - 1];
        }
    }

    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; i + j <= n + 1; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    */

    scanf(" %d", &q);
    vector<query> queries;
    int l, r;
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d", &l, &r);
        queries.emplace_back(l, r, i);
    }

    sort(begin(queries), end(queries));
    reverse(begin(queries), end(queries));
    int idx;
    cur[1] = res[n][1];
    int pos = n;
    for (auto& query : queries) {
        tie(l, r, idx) = query;
        while (l < pos) {
            /*
            printf("Col was:\n"); 
            for (int i = 1; pos + i <= n + 1; ++i) {
                printf("%d\n", cur[i]);
            }
            */

            --pos;
            // printf("Shifting to %d\n", pos);

            for (int j = 1; pos + j <= n + 1; ++j) {
                // printf("Up: %d diag: %d cell %d\n", cur2[j - 1], cur[j - 1], res[pos][j]);
                cur2[j] = max(cur2[j - 1], cur[j - 1]);
                cur2[j] = max(cur2[j], res[pos][j]);
            }

            // printf("Col now:\n"); 
            for (int i = 1; pos + i <= n + 1; ++i) {
                cur[i] = cur2[i];
                // printf("%d\n", cur[i]);
            }
        }

        ans[idx] = cur[r - l + 1];
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
