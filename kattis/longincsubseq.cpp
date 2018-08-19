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

    int n;
    while (scanf(" %d", &n) == 1) {
        vector<ll> a(n + 1);
        a[0] = -1e18;
        for (int i = 1; i <= n; ++i) {
            scanf(" %lld", &a[i]);
        }

        vector<int> link(n + 1, -1);
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; ++i) {
            if (a[i] > a[v.back()]) {
                link[i] = v.back();
                v.push_back(i);
            } else {
                int lo = 0;
                int hi = v.size() - 1;
                while (lo + 1 < hi) {
                    int mid = (lo + hi) >> 1;
                    if (a[i] <= a[v[mid]]) {
                        hi = mid;
                    } else {
                        lo = mid;
                    }
                }

                link[i] = v[lo];
                v[hi] = i;
            }
        }

        printf("%d\n", static_cast<int>(v.size()) - 1);
        vector<int> stk;
        stk.push_back(v.back());
        while (link[stk.back()] > 0) {
            stk.push_back(link[stk.back()]);
        }

        assert(stk.size() + 1 == v.size());
        reverse(begin(stk), end(stk));
        for (int x : stk) {
            printf("%d ", x - 1);
        }
        printf("\n");
    }

    return 0;
}
