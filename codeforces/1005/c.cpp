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

constexpr ll CAP = 2e9;
constexpr int MAXN = 2e5+ 5;

int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    map<ll, int> freq;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", a + i);
        ++freq[a[i]];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        --freq[a[i]];

        bool found = false;
        for (ll p = 2; p <= CAP; p <<= 1LL) {
            ll goal = p - a[i];
            // printf("%d + goal %d = %d\n", a[i], goal, p);
            found |= freq[goal] > 0;
        }

        ++freq[a[i]];

        if (!found) {
            // printf("No find for %lld\n", a[i]);
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
