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

inline ll fast(ll x) {
    x -= 1;
    return x - (x / 3);
}

/*
ll sod(ll x) {
    if (x < 10) return x;
    return (x % 10) + sod(x / 10);
}

ll slow(ll x) {
    int ans = 0;
    for (ll i = 1; i <= x; ++i) {
        ll res = 0LL;
        for (int j = 1; j <= i; ++j) {
            res += sod(j);
            res %= 3;
        }

        if (res == 0)
            ++ans;
    }

    return ans;
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 1, 1+2 = 0, 0 + 3 = 0, 0 + 1 = 1, 1 + 2 = 0, 
    // 1, 0, 0, 1, 0, 0, 1, 0, 0
    ll x;
    scanf(" %lld", &x);
    ll f = fast(x);
    printf("%lld\n", f);
    
    return 0;
}
