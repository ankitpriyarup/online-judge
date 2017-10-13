#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int n, m;
int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    
    map<ll, int> freq;
    freq[0] = 1;
    ll cum = 0LL;
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        cum += a[i];
        cum %= m;

        ans += freq[cum];
        ++freq[cum];
    }

    printf("%lld\n", ans);

    return 0;
}
