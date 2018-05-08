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

constexpr int MAXN = 111;
int n, m;
ll a[MAXN];
int inds[MAXN];
int two[MAXN], three[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", a + i);
        ll x = a[i];
        while (x % 3 == 0) {
            ++three[i];
            x /= 3;
        }
        while (x % 2 == 0) {
            ++two[i];
            x /= 2;
        }

        inds[i] = i;
    }

    sort(inds, inds + n, [](const int& i1, const int& i2) {
        if (three[i1] != three[i2]) {
            return three[i1] > three[i2];
        } else {
            return two[i1] < two[i2];
        }
    });

    for (int i = 0; i < n; ++i) {
        printf("%lld ", a[inds[i]]);
    }

    return 0;
}
