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
int n;
ll a[MAXN];
ll b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
    }

    if (n <= 2) {
        printf("0\n");
        return 0;
    }

    bool poss = false;
    int ans = n + 5;
    for (int d0 = -1; d0 <= 1; ++d0) {
        for (int d1 = -1; d1 <= 1; ++d1) {
            b[0] = a[0] + d0;
            b[1] = a[1] + d1;
            bool thisposs = true;
            int moves = (d0 != 0) + (d1 != 0);
            ll delta = b[1] - b[0];

            // printf("Starting with %lld %lld\n", b[0], b[1]);
            for (int i = 2; i < n; ++i) {
                // want b[i - 1] + delta = a[i]
                ll exp = b[i - 1] + delta;
                // printf("Want b[%d] = %lld\n", i, exp);
                if (a[i] == exp) {
                    b[i] = a[i];
                } else if (abs(a[i] - exp) == 1) {
                    ++moves;
                    b[i] = b[i - 1] + delta;
                } else {
                    thisposs = false;
                    break;
                }
            }

            if (thisposs) {
                poss = true;
                ans = min(ans, moves);
            }
        }
    }

    printf("%d\n", poss ? ans : -1);
    return 0;
}
