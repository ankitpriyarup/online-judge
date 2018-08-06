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

    int k, n;
    scanf(" %d", &k);
    map<ll, map<int, int>> m;
    for (int i = 1; i <= k; ++i) {
        scanf(" %d", &n);
        vector<int> v(n);
        ll tot = 0LL;
        for (int j = 1; j <= n; ++j) {
            scanf(" %d", &v[j - 1]);
            tot += v[j - 1];
        }

        for (int j = 1; j <= n; ++j) {
            ll part_sum = tot - v[j - 1];
            m[part_sum][i] = j;
        }
    }

    for (auto p : m) {
        if (p.second.size() > 1) {
            printf("YES\n");
            auto it = begin(p.second);
            for (int x = 0; x < 2; ++x, it = next(it))
                printf("%d %d\n", it->first, it->second);
            return 0;
        }
    }

    printf("NO\n");
    
    return 0;
}
