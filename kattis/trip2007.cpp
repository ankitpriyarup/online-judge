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

vector<vector<int>> can(const vector<int>& a, int slots) {
    vector<vector<int>> res(slots);
    int k = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i, k = (k + 1) % slots) {
        if (!res[k].empty() and res[k].back() == a[i])
            return {};
        res[k].push_back(a[i]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (scanf(" %d", &n) == 1) {
        if (n == 0) break;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
        }
        sort(begin(a), end(a));
        int lo = 0;
        int hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            if (!can(a, mid).empty()) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        auto res = can(a, hi);
        printf("%lu\n", res.size());
        for (const vector<int>& row : res) {
            for (int x : row) {
                printf("%d ", x);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
