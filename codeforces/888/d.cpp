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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf("%d %d", &n, &k);
    ll ans = 0;

    if (k >= 4) {
        ans += 1LL * n * (n - 1) * (n - 2) * (n - 3) / 8LL;

        ans += 1LL * n * (n - 1) / 2LL * (n - 2) * (n - 3) / 2LL;
    }
    if (k >= 3) {
        ans += 1LL * n * (n - 1) * (n - 2) / 3LL;
    }
    if (k >= 2) {
        ans += 1LL * n * (n - 1) / 2LL;
    }
    if (k >= 1) {
        ans += 1;
    }

    printf("%lld\n", ans);
    
    return 0;
}
