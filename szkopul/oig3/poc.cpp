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
using pii = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    int last = -1;
    int x;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x >= m) {
            res += 1LL * (i - last) * (n - i);
            last = i;
        }
    }

    printf("%lld\n", res);

    return 0;
}
