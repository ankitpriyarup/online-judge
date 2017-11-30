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

int n, p;
int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] -= p;
    }

    ll best = 0;
    ll cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur = max(0LL, cur + a[i]);
        best = max(cur, best);
    }

    printf("%lld\n", best);
    
    return 0;
}
