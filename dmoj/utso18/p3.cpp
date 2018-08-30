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

    int n, t, k, v;
    scanf(" %d %d %d %d", &n, &t, &k, &v);
    vector<char> has_restaurant(n);
    set<int> spots;
    int x;
    for (int i = 0; i < v; ++i) {
        scanf(" %d", &x);
        --x;
        ++has_restaurant[x];
    }

    for (int i = 0; i < n; ++i) {
        if (!has_restaurant[i])
            spots.insert(i);
    }

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < t; ++i) {
        sum += has_restaurant[i];
    }

    for (int i = t; i <= n; ++i) {
        // range [i - t, i)
        while (sum < k) {
            auto it = prev(spots.lower_bound(i));
            has_restaurant[*it] = true;
            ++sum;
            ++ans;
            spots.erase(it);
        }
        if (i < n) {
            sum -= has_restaurant[i - t];
            sum += has_restaurant[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
