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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        scanf(" %lld", &a[i]);

    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    ll cur = 1;
    ll ans = 1;
    for (ll x : a) {
        cur *= x;
        ans += cur;
    }

    printf("%lld\n", ans);

    
    return 0;
}
