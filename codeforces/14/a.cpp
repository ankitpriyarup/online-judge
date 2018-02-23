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

constexpr int MAXN = 102;
int n, m;
char grid[MAXN][MAXN];

bool dot_row(int r) {
    for (int c = 0; c < m; ++c)
        if (grid[r][c] == '*')
            return false;
    return true;
}

bool dot_col(int c) {
    for (int r = 0; r < n; ++r)
        if (grid[r][c] == '*')
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", grid[i]);

    int top = 0;
    int bot = n - 1;
    while (dot_row(top))
        ++top;
    while (dot_row(bot))
        --bot;

    int left = 0;
    int right = m - 1;

    while (dot_col(left))
        ++left;
    while (dot_col(right))
        --right;

    for (int i = top; i <= bot; ++i) {
        grid[i][right + 1] = '\0';
        printf("%s\n", &grid[i][left]);
    }

    return 0;
}
