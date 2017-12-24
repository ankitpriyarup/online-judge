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

    int n;
    int a, b;
    while (scanf("%d", &n) == 1) {
        if (n == -1) break;

        ll ans = 0LL;
        int last = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            ans += 1LL * a * (b - last);
            last = b;
        }

        printf("%lld miles\n", ans);
    }
    
    return 0;
}
