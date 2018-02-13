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

constexpr int MAXK = 1000006;
int n, k;
int a[MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    a[0] = 0;
    for (int i = 1; i <= k; ++i) {
        scanf("%d", a + i);
    }

    ll ans = 0LL;

    for (int i = 1; i + 2 <= k; ++i) {
        int starts = a[i] - a[i - 1];
        int ends = n - a[i + 2] + 1;

        // printf("Start %d starts %d ends %d\n", a[i], starts, ends);

        ans += 1LL * starts * ends;
    }
    
    printf("%lld\n", ans);

    return 0;
}
