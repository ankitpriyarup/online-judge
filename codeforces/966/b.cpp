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

constexpr int MAXN = 300005;
int n;
ll x1, x2;
pair<ll, int> a[MAXN];

int solve(int start) {
    int lo = 0;
    int hi = n;
    ll val = a[start].first;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        assert(mid > 0);
        if ((x1 + mid - 1) / mid > val)
            lo = mid;
        else
            hi = mid;
    }

    int k1 = hi;
    assert(k1 > 0);
    if (start + k1 > n || a[start].first < (x1 + k1 - 1) / k1)
        return false;
    int k2 = n - start - k1;
    if (k2 <= 0)
        return false;

    ll need = (x2 + k2 - 1) / k2;
    if (a[start + k1].first < need)
        return false;

    return k1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x;
    scanf(" %d %lld %lld", &n, &x1, &x2);

    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &x);
        a[i] = {x, i + 1};
    }
    sort(a, a + n);

    for (int swapped = 0; swapped < 2; ++swapped) {
        for (int i = n - 2; i >= 0; --i) {
            int res = solve(i);
            if (res > 0) {
                printf("Yes\n");
                if (swapped)
                    printf("%d %d\n", n - i - res, res);
                else
                    printf("%d %d\n", res, n - i - res);

                if (swapped) {
                    for (int j = i + res; j < n; ++j) {
                        printf("%d ", a[j].second);
                    }
                    printf("\n");
                    for (int j = i; j < i + res; ++j) {
                        printf("%d ", a[j].second);
                    }
                    printf("\n");
                } else {
                    for (int j = i; j < i + res; ++j) {
                        printf("%d ", a[j].second);
                    }
                    printf("\n");
                    for (int j = i + res; j < n; ++j) {
                        printf("%d ", a[j].second);
                    }
                    printf("\n");
                }
                return 0;
            }
        }
        swap(x1, x2);
    }

    printf("No\n");
    return 0;
}
