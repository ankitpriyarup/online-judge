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
int sod[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < 10; ++i) {
        sod[i] = i;
    }
    for (int i = 10; i <= n; ++i) {
        sod[i] = sod[i / 10] + (i % 10);
    }

    int ans = 1e9 + 7;
    for (int a = 1; a < n; ++a) {
        ans = min(ans, sod[a] + sod[n - a]);
    }

    printf("%d\n", ans);
    
    return 0;
}
