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

constexpr int MAXN = 2003;
int n, m;
char grid[MAXN][MAXN];

bool works(int k) {
    set<string> s;

    for (int j = 0; j < m; ++j) {
        string col = "";
        for (int i = k; i < n; ++i) {
            col.push_back(grid[i][j]);
        }

        s.insert(col);
    }

    return s.size() == m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);
    }

    int lo = 0;
    int hi = n;

    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", lo);
    
    return 0;
}
