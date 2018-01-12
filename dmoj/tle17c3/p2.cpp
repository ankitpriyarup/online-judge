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

constexpr int MAXN = 100005;
int inv[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s, k;
    scanf("%d %d", &s, &k);

    int x;
    for (int i = 1; i <= s; ++i) {
        scanf("%d", &x);
        inv[x] = i;
    }

    int pos, nxt;
    scanf("%d", &pos);
    pos = inv[pos];
    ll ans = 1;
    for (int i = 1; i < k; ++i) {
        scanf("%d", &nxt);
        nxt = inv[nxt];
        ans += abs(nxt - pos);
        pos = nxt;
    }

    printf("%lld\n", ans);
    
    return 0;
}
