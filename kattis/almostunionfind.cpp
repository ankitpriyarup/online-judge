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

constexpr int MAXN = 100005;
int n;
set<int> sets[MAXN];
ll sums[MAXN];

// where is x located?
int loc[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    while (scanf(" %d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; ++i) {
            sets[i].clear();
            sets[i].insert(i);
            sums[i] = i;
            loc[i] = i;
        }

        int op;
        int a, b;
        while (q-- > 0) {
            scanf(" %d", &op);
            if (op == 1) {
                scanf(" %d %d", &a, &b);
                int a_id = loc[a];
                int b_id = loc[b];

                if (a_id == b_id) continue;
                if (sets[a_id].size() < sets[b_id].size()) {
                    for (int x : sets[a_id]) {
                        loc[x] = b_id;
                        sets[b_id].insert(x);
                        sums[b_id] += x;
                    }

                    sums[a_id] = 0;
                    sets[a_id].clear();
                } else {
                    for (int x : sets[b_id]) {
                        loc[x] = a_id;
                        sets[a_id].insert(x);
                        sums[a_id] += x;
                    }

                    sums[b_id] = 0;
                    sets[b_id].clear();
                }
            } else if (op == 2) {
                scanf(" %d %d", &a, &b);
                int old_id = loc[a];
                int new_id = loc[b];
                if (old_id == new_id) continue;
                sums[old_id] -= a;
                sums[new_id] += a;
                sets[old_id].erase(a);
                sets[new_id].insert(a);
                loc[a] = new_id;
            } else {
                scanf(" %d", &a);
                int id = loc[a];
                printf("%lu %lld\n", sets[id].size(), sums[id]);
            }
        }
    }

    return 0;
}
