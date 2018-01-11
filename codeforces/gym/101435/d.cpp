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

constexpr int MAXN = 1e6 + 6;
constexpr int INF = 1e9;
int n;
int a[MAXN];
int diff[MAXN];

int score(int x) {
    if (n == 1) {
        return (a[0] & 1) != x;
    }

    int ret = INF;
    for (int k = 0; k < 2; ++k) {
        // printf("k = %d\n", k);
        memset(diff, 0, sizeof(diff));
        diff[0] = diff[1] = k;
        int cur = k;

        for (int i = 1; i < n; ++i) {
            if (((a[i - 1] + diff[i - 1]) % 2) != x) {
                // printf("hitting %d\n", i);
                ++cur;
                for (int d = -1; d <= 1; ++d)
                    diff[i + d] += 1;
            }
        }

        if (((a[n - 1] + diff[n - 1]) % 2) == x) {
            // printf("cur = %d\n", cur);
            ret = min(ret, cur);
        }
    }

    return ret == INF ? -1 : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    printf("%d\n%d\n", score(1), score(0));

    return 0;
}
