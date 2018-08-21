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

constexpr int MAXN = 200005;
int n, k;
int a[MAXN], b[MAXN];

struct f_tree {
    int data[MAXN];
    
    f_tree() {
        memset(data, 0, sizeof(data));
    }

    int query(int x) const {
        ll ans = 0LL;
        for (int i = x; i; i -= (i & -i)) {
            ans += data[i];
        }

        return ans;
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        return query(min(MAXN - 1, r)) - query(max(0, l - 1));
    }

    void update(int x, int v) {
        for (int i = x; i < MAXN; i += (i & -i)) {
            data[i] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    f_tree zeros;
    vector<vector<int>> pos(k + 1);
    vector<vector<int>> starts(n + 2);
    vector<vector<int>> ends(n + 2);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
        if (a[i] == 0) {
            zeros.update(i, 1);
        }

        pos[a[i]].push_back(i);
    }

    int skipped = 0;
    for (int v = k; v >= 1; --v) {
        // printf("val %d\n", v);
        if (pos[v].empty()) {
            ++skipped;

            if (v == k) {
                // set the first 0 to k
                if (pos[0].empty()) {
                    printf("NO\n");
                    return 0;
                }

                starts[pos[0][0]].push_back(v);
                ends[pos[0][0] + 1].push_back(v);
            }
            continue;
        }
        // find the largest expanse which is all equal to v or 0
        int l = pos[v][0];
        int r = pos[v].back();

        // printf("orig range [%d %d]\n", l, r);

        // expand west
        int lo = 0;
        int hi = l + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            int found = zeros.query(l - mid, l - 1);
            if (found == mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        l -= lo;

        // east
        lo = 0;
        hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            int found = zeros.query(r + 1, r + mid);
            if (found == mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        r += lo;
        // printf("Expand range [%d, %d]\n", l, r);

        int have = zeros.query(l, r) + pos[v].size();
        // printf("Have %d want %d\n", have, r - l + 1);
        if (have != r - l + 1) {
            printf("NO");
            return 0;
        }

        starts[l].push_back(v);
        ends[r + 1].push_back(v);
        for (int x : pos[v]) {
            // printf("Updating %d\n", x);
            zeros.update(x, 1);
        }
    }

    bool foundk = false;
    if (skipped == k) {
        for (int i = 1; i <= n; ++i) {
            b[i] = k;
        }
        foundk = true;
    } else {
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            for (int x : starts[i]) {
                s.insert(x);
            }
            for (int x : ends[i]) {
                s.erase(s.find(x));
            }

            if (s.empty()) {
                printf("NO\n");
                return 0;
            }

            b[i] = *prev(end(s));
            foundk |= b[i] == k;
        }
    }

    if (!foundk) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
