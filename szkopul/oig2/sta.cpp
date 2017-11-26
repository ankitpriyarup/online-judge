#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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
ll f[3];
int n[3];
ll a[3][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int idx = 0; idx < 3; ++idx) {
        scanf("%lld", f + idx);
    }

    ll target = 0;
    for (int idx = 0; idx < 3; ++idx) {
        scanf("%d", n + idx);
        for (int i = 0; i < n[idx]; ++i) {
            scanf("%lld", &a[idx][i]);
            a[idx][i] *= f[idx];
        }
        sort(a[idx], a[idx] + n[idx]);

        target += a[idx][n[idx] - 1];
    }

    target = target / 2;

    ll ans = 0;
    for (int i = 0; i < n[0]; ++i) {
        for (int j = 0; j < n[1]; ++j) {
            ll score = a[0][i] + a[1][j];
            ll wanted = target - score;
            // printf("Cur score: %lld, wanted: %lld\n", score, wanted);

            int ind = upper_bound(a[2], a[2] + n[2], wanted) - a[2];
            // printf("ind: %d / %d\n", ind, n[2]);
            ans = ans + (n[2] - ind);

            // printf("Found %d\n", n[2] - ind);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
