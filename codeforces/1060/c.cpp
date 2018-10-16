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

    int n, m;
    scanf(" %d %d", &n, &m);
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %lld", &b[i]);
    }

    ll x;
    scanf(" %lld", &x);

    constexpr ll INF = 1e18;
    vector<ll> min_a_sum(n + 1, INF);
    min_a_sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        ll s = a[i];
        min_a_sum[1] = min(min_a_sum[1], s);

        for (int j = i + 1; j < n; ++j) {
            s += a[j];
            min_a_sum[j - i + 1] = min(s, min_a_sum[j - i + 1]);
        }
    }

    int ans = 0;
    for (int b_len = 1; b_len <= m; ++b_len) {
        ll cur_sum = 0;
        for (int i = 0; i < b_len; ++i)
            cur_sum += b[i];
        ll min_sum = cur_sum;
        for (int i = b_len; i < m; ++i) {
            cur_sum -= b[i - b_len];
            cur_sum += b[i];
            min_sum = min(min_sum, cur_sum);
        }

        int a_len = upper_bound(begin(min_a_sum), end(min_a_sum), x / min_sum) - begin(min_a_sum) - 1;
        if (a_len > 0)
            ans = max(ans, b_len * a_len);
    }

    printf("%d\n", ans);

    return 0;
}
