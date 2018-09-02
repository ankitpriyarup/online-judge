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
    int n; ll s;

    scanf(" %d %lld", &n, &s);
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &v[i]);
    }

    sort(begin(v), end(v));

    ll a1 = 0LL;
    ll a2 = 0LL;
    for (int i = 0; i < n / 2; ++i) {
        a1 += max(0LL, v[i] - s);
    }
    for (int i = n / 2 + 1; i < n; ++i) {
        a2 += max(0LL, s - v[i]);
    }

    printf("%lld\n", a1 + a2 + abs(v[n / 2] - s));

    return 0;
}
