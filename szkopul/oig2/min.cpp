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

constexpr int MAXN = 1e6 + 6;
int n;
ll k;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);

    sort(a, a + n);
    // a[ptr] is the greatest thing that's <= val
    // Can go off end!
    int ptr = 0;
    for (ll val = k; ; val += k) {
        while (ptr + 1 < n and a[ptr + 1] <= val)
            ++ptr;
        if (a[ptr] != val) {
            printf("%lld\n", val);
            return 0;
        }
    }

    return 0;
}
