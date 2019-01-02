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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    scanf(" %d", &k);
    int a;
    int extra = 0;
    int cur = 1;
    int ans = 0;

    for (int i = 0; i < k; ++i) {
        scanf(" %d", &a);
        if ((a & 1) and extra == 0) {
            ans += cur;
            if (ans >= MOD)
                ans -= MOD;
        }

        extra += a;
        extra >>= 1;

        cur <<= 1;
        if (cur >= MOD)
            cur -= MOD;
    }

    printf("%d\n", ans);
    
    return 0;
}
