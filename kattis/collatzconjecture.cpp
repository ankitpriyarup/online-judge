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

constexpr int MAXN = 500005;
int n;
ll a[MAXN];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    set<ll> total;
    set<ll> cur;
    for (int i = 0; i < n; ++i) {
        set<ll> new_cur;
        for (const ll& x : cur) {
            ll y = gcd(x, a[i]);
            new_cur.insert(y);
        }
        new_cur.insert(a[i]);
        cur = new_cur;

        total.insert(begin(cur), end(cur));
    }

    printf("%lu\n", total.size());

    return 0;
}
