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

constexpr int MAXN = 5003;
int n;
int a[MAXN], aa[MAXN], b[MAXN], bb[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool first = true;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        if (!first) printf("\n");

        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            aa[i] = a[i];
        }

        sort(aa, aa + n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", b + i);
            bb[i] = b[i];
        }

        sort(bb, bb + n);

        for (int i = 0; i < n; ++i) {
            int ind = lower_bound(aa, aa + n, a[i]) - aa;
            printf("%d\n", bb[ind]);
        }

        first = false;
    }
    
    return 0;
}
