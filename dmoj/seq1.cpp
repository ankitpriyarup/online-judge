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

constexpr int MOD = 1e9 + 7;
// F_i = 2 * F_{i - 1} + 7
struct mat {
    int data[2][2];
} pows[64];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    scanf(" %lld", &n);

    pows[0].data[0][0] = 2;
    pows[0].data[0][1] = 7;
    pows[0].data[1][0] = 0;
    pows[0].data[1][1] = 1;

    for (int p = 0; p + 1 < 64; ++p) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    pows[p + 1].data[i][j] += 1LL * pows[p].data[i][k] * pows[p].data[k][j] % MOD;
                    while (pows[p + 1].data[i][j] >= MOD)
                        pows[p + 1].data[i][j] -= MOD;
                }
            }
        }
    }

    int x = 1;
    int y = 1;

    for (ll p = 0; p < 64; ++p) {
        if (n & (1LL << p)) {
            int nx = 1LL * pows[p].data[0][0] * x % MOD + 1LL * pows[p].data[0][1] * y % MOD;
            while (nx >= MOD)
                nx -= MOD;

            int ny = 1LL * pows[p].data[1][0] * x % MOD + 1LL * pows[p].data[1][1] * y % MOD;
            while (ny >= MOD)
                ny -= MOD;

            x = nx;
            y = ny;
        }
    }

    printf("%d\n", (x + 2) % MOD);

    return 0;
}
