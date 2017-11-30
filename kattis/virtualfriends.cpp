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
using pii = pair<int, int>;

namespace uf {
    vector<int> par;
    vector<int> size;
    void init(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x]) ? x : find(par[x]);
    }

    void merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);

        if (xr == yr) return;

        par[xr] = yr;
        size[yr] += size[xr];
        size[xr] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    string a, b;
    while (T-- > 0) {
        int n;
        cin >> n;
        map<string, int> id;
        uf::init(2 * n + 1);

        while (n-- > 0) {
            cin >> a >> b;
            if (id.find(a) == end(id)) {
                int x = id.size();
                id[a] = x;
            }

            if (id.find(b) == end(id)) {
                int x = id.size();
                id[b] = x;
            }

            uf::merge(id[a], id[b]);
            printf("%d\n", uf::size[uf::find(id[a])]);
        }
    }

    return 0;
}
