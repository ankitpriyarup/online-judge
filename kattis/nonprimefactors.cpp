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

constexpr int MAXN = 2000006;
int sieve[MAXN];
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve[1] = 1;
    sieve[2] = 0;
    for (int d = 2; d < MAXN; ++d) {
        if (!sieve[d]) {
            for (int j = d + d; j < MAXN; j += d) {
                sieve[j] = 1;
            }
        } else {
            for (int j = d; j < MAXN; j += d) {
                ans[j] += 1;
            }
        }
    }

    int q, x;
    scanf(" %d", &q);
    while (q-- > 0) {
        scanf(" %d", &x);
        printf("%d\n", ans[x] + 1);
    }

    return 0;
}
