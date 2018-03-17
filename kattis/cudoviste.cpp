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

int n, m;
char grid[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    vector<int> ans(5, 0);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int x = 0;
            int hash = 0;
            for (int dx = -1; dx <= 0; ++dx) {
                for (int dy = -1; dy <= 0; ++dy) {
                    if (grid[i + dx][j + dy] == 'X')
                        ++x;
                    else if (grid[i + dx][j + dy] == '#')
                        ++hash;
                }
            }

            if (hash == 0) {
                ++ans[x];
            }
        }
    }

    for (int i = 0; i < 5; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
