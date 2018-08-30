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

namespace uf {
    vector<int> uf;

    void init(const int& n) {
        uf.resize(n);
        iota(begin(uf), end(uf), 0);
    }

    int find(int x) {
        return uf[x] = uf[x] == x ? x : find(uf[x]);
    }

    bool join(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        uf[xr] = yr;
        return true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);
    uf::init(n + 1);
    int u, v;
    while (m-- > 0) {
        scanf(" %d %d", &u, &v);
        uf::join(u, v);
    }

    bool printed = false;
    for (int i = 1; i <= n; ++i) {
        if (uf::find(i) != uf::find(1)) {
            printf("%d\n", i);
            printed = true;
        }
    }

    if (!printed) {
        printf("Connected\n");
    }

    return 0;
}
