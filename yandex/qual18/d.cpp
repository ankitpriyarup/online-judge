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
constexpr int MAXK = 101;
int n;
pair<ll, int> a[MAXN];
pair<ll, int> b[MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i].first);
        a[i].second = i + 1;
    }

    int l, r;
    while (q-- > 0) {
        scanf("%d %d", &l, &r);
        --l; --r;

        int len = min(r - l + 1, MAXK);
        for (int i = 0; i < len; ++i) {
            b[i] = a[l + i];
        }

        sort(b, b + len);
        bool found = false;
        for (int i = 2; i < len; ++i) {
            if (b[i - 2].first + b[i - 1].first > b[i].first) {
                printf("%d %d %d\n", b[i - 2].second, b[i - 1].second, b[i].second);
                found = true;
                break;
            }
        }

        if (!found) {
            printf("%d\n", -1);
        }
    }

    return 0;
}
