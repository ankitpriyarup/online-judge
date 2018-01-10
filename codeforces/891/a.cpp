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

constexpr int MAXN = 2003;
int n;
int a[MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int d = a[0];
    for (int i = 1; i < n; ++i) {
        d = gcd(d, a[i]);
    }

    if (d != 1) {
        printf("%d\n", -1);
        return 0;
    }

    // (min number of moves to get a 1) + n - 1
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        for (int j = i + 1; j < n; ++j) {
            cur = gcd(cur, a[j]);
            if (cur == 1) {
                ans = min(ans, j - i - 1);
            }
        }
        if (a[i] == 1)
            ans = 0;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != 1)
            ++ans;
    }

    printf("%d\n", ans);

    return 0;
}
