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

constexpr int MAXN = 1003;
int n;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d", &n);
        int res = 0;
        int run = 1;
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
            run = (1LL * run * a[i]) % 9;
            res += run;
            if (res >= 9) res -= 9;
        }

        if (!res) res = 9;
        printf("%d\n", res);
    }

    
    return 0;
}
