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

constexpr int MAXN = 1505;
constexpr int INF = 1e9;
int n;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    bool inv = false;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i])
                inv = !inv;
        }
    }

    int q;
    scanf("%d", &q);
    int l, r;
    while (q-- > 0) {
        scanf("%d %d", &l, &r);
        int len = r - l + 1;
        int sz = len * (len - 1) / 2;
        if (sz & 1)
            inv = !inv;
        printf("%s\n", inv ? "odd" : "even");
    }

    return 0;
}
