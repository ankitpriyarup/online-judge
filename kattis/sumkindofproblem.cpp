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

    int T;
    scanf("%d", &T);

    int tc, n;
    while (T-- > 0) {
        scanf("%d %d", &tc, &n);
        ll ans = 1LL * n * (n + 1) / 2;
        printf("%d %lld %lld %lld\n", tc, ans, 2LL * ans - n, 2LL * ans);
    }
    
    return 0;
}
