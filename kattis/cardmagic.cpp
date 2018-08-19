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

    constexpr int MOD = 1e9 + 9;

    int n, k, t;
    scanf(" %d %d %d", &n, &k, &t);
    vector<int> old(t + 1, 0);
    vector<int> cur(t + 1, 0);

    old[0] = 1;
    for (int p = 1; p <= n; ++p) {
        for (int s = 0; s <= t; ++s) {
            for (int v = 1; v <= k and s + v <= t; ++v) {
                cur[s + v] += old[s];
                if (cur[s + v] >= MOD)
                    cur[s + v] -= MOD;
            }
        }

        swap(old, cur);
        cur.assign(t + 1, 0);
    }

    printf("%d\n", old[t]);

    return 0;
}
