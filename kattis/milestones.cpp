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

constexpr int MAXN = 1003;
constexpr ld EPS = 1.0e-10;
int n, m;
ll a[MAXN], b[MAXN];
bool dp[MAXN][MAXN];

bool equal(ll num1, ll den1, ll num2, ll den2) {
    ld x = num1 / static_cast<ld>(den1);
    ld y = num2 / static_cast<ld>(den2);

    return abs(x - y) < EPS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    for (int i = 0; i < m; ++i)
        scanf("%lld", b + i);

    vector<ll> ans;
    for (int offset = 0; offset <= m - n; ++offset) {
        bool valid = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (!equal(a[i + 1] - a[i], b[offset + i + 1] - b[offset + i],
                       a[1] - a[0], b[offset + 1] - b[offset])) {
                valid = false;
            }
        }

        if (valid) {
            ans.push_back(b[offset + 1] - b[offset]);
        }
    }

    sort(begin(ans), end(ans));
    ans.resize(unique(begin(ans), end(ans)) - begin(ans));
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 1; i <= sz; ++i) {
        printf("%lld%c", ans[i - 1], " \n"[i == sz]);
    }

    return 0;
}
