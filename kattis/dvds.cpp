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

constexpr int MAXN = 1e6 + 6;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, x;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        int exp = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x == exp + 1)
                ++exp;
        }

        printf("%d\n", n - exp);
    }

    return 0;
}
