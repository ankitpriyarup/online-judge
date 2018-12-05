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

constexpr int MAXN = 500005;
int loc[MAXN];
vector<int> ing[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d", &n);
    memset(loc, -1, sizeof(loc));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &m);
        bool can_make = true;
        map<int, int> deps;
        ing[i].resize(m);
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &ing[i][j]);
            if (loc[ing[i][j]] != -1)
                deps[loc[ing[i][j]]] += 1;
        }

        for (auto y : deps) {
            can_make &= ing[y.first].size() == y.second;
            if (!can_make)
                break;
        }
        
        if (can_make) {
            ++ans;
            for (int y : ing[i]) {
                loc[y] = i;
            }
            for (auto y : deps) {
                ing[y.first].clear();
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
