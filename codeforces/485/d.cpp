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

bool contains(const vector<int>& a, int v) {
    auto it = lower_bound(begin(a), end(a), v);
    return it != end(a) and *it == v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    n = a.size();
    int ans = 0;
    /*
    // O(1000 n) for small mods
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i and a[j] < 1000; ++j) {
            ans = max(ans, a[i] % a[j]);
        }
    }
    */

    // answer is [1, 5 * 10^5)
    // can we see if an answer is possible in O(1)?
    // a % b = c
    // exists k such that kb + c = a, k >= 1
    // iterate over all k? Then each value is considered 10^6 / a[i] times
    // O(n logN logM)
    for (int j = 0; j < n; ++j) {
        for (int v = a[j]; v <= a.back(); v += a[j]) {
            int up = v + a[j];
            // find the maximum value we have in range (v, v + a[j])
            auto it = lower_bound(begin(a), end(a), up);
            if (it == begin(a)) continue;
            it = prev(it);
            if (*it <= v or up <= *it) continue;
            ans = max(ans, *it - v);
        }
    }

    cout << ans << '\n';

    return 0;
}
