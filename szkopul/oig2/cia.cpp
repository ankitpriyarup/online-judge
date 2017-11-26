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
using pii = pair<ll, ll>;

constexpr int CAP1 = 1e5;

// sum of [a, b]
inline ll sum(ll a, ll b) {
    return (b * (b + 1) - a * (a - 1)) / 2LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    scanf("%lld", &n);

    vector<int> ans = {0, 1, 2, 2, 3, 3};
    if (n <= 5) {
        printf("%d\n", ans[n]);
        return 0;
    }

    /*
     * a[3] = 2
     * This generates a[6-11] using 4 and 5
     * Which generates a[12-38] using values [6-11]
     */

    /* More generally, say a[i] = k
     * This generates some first layer of answers a[x1-x2] using values
     * Which in turn generates a[y1-y2] using values x1-x2
     */

    /* List of first layers
     * Size 2, 2 of them, values 2-3, indexes 2-5
     * Size 3, 2 of them, values 4-5, indexes 6-11
     * Size 4, 3 of them, values 6-8, indexes 12-23
     * Size 5, 3 of them, values 9-11, indexes 24-38
     */

    /* List of second layers
     * a[2] = 2, values 2-5, indexes 2-11
     * a[3] = 2, values 6-11, indexes 12-38
     * a[4] = 3, values 12-23 indexes 39-122
     */

    /*
     * In general, the values of the second layer are the
     * indexes from the first layer.
     */

    // size of each thing in layer, starting value for layer
    pair<pii, pii> layer1 = {{2, 3}, {2, 5}};
    pair<pii, pii> layer2 = {{2, 5}, {2, 11}};
    int start_freq = 2;
    for (int i = 3; layer2.second.second < n; ++i) {
        ll val_start = layer1.first.second + 1;
        ll val_end = val_start + ans[i] - 1;

        ll ind_start = layer1.second.second + 1;
        ll ind_end = ind_start + ans[i] * i - 1;

        layer1 = {{val_start, val_end}, {ind_start, ind_end}};
        // printf("layer 1: {{%lld, %lld}, {%lld, %lld}}\n", val_start, val_end, ind_start, ind_end);
        for (int v = val_start; ans.size() < CAP1 and v <= val_end; ++v) {
            for (int k = 0; k < i; ++k)
                ans.push_back(v);
        }

        ll l2s = layer2.second.second + 1;
        ll l2e = l2s + 1LL * i * sum(val_start, val_end) - 1;
        layer2 = {{ind_start, ind_end}, {l2s, l2e}};
        start_freq = i;
        // printf("layer 2: {{%lld, %lld}, {%lld, %lld}}\n", ind_start, ind_end, l2s, l2e);
    }

    // printf("Start freq: %d\n", start_freq);
    // printf("layer 1: {{%lld, %lld}, {%lld, %lld}}\n", layer1.first.first, layer1.first.second, layer1.second.first, layer1.second.second);
    // printf("layer 2: {{%lld, %lld}, {%lld, %lld}}\n", layer2.first.first, layer2.first.second, layer2.second.first, layer2.second.second);

    ll last_ind =  layer2.second.first;
    ll last_val = layer2.first.first;
    for (ll i = layer1.first.first; i <= layer1.first.second; ++i) {
        ll end = layer2.second.first + 1LL * start_freq * sum(layer1.first.first, i) - 1;
        ll end_val = last_val + start_freq - 1;
        // printf("shrunk: %lld | {%lld, %lld} {%lld, %lld}\n", i, last_val, end_val, last_ind, end);

        if (end >= n) {
            ll ret = n - last_ind;
            // printf("%lld\n", ret);

            ret /= i;
            // printf("%lld\n", ret);

            ret += last_val;
            printf("%lld\n", ret);

            return 0;
        }

        last_ind = end + 1;
        last_val = end_val + 1;
    }

    return 0;
}
