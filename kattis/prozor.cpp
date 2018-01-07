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
int n, m, k;
char grid[MAXN][MAXN];
int psum[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + (grid[i][j] == '*');
        }
    }

    k -= 2;
    int brx = 0;
    int bry = 0;
    int best = -1;
    for (int i = k; i + 1 < n; ++i) {
        for (int j = k; j + 1 < m; ++j) {
            int sum = psum[i][j] - psum[i - k][j] - psum[i][j - k] + psum[i - k][j - k];
            if (sum > best) {
                best = sum;
                brx = i;
                bry = j;
            }
        }
    }

    ++brx;
    ++bry;
    ++k;
    for (int i = brx - k; i <= brx; ++i) {
        grid[i][bry - k] = '|';
        grid[i][bry] = '|';
    }

    for (int j = bry - k; j <= bry; ++j) {
        grid[brx - k][j] = '-';
        grid[brx][j] = '-';
    }


    for (int dx = -1; dx <= 0; ++dx)
        for (int dy = -1; dy <= 0; ++dy)
            grid[brx + dx * k][bry + dy * k] = '+';

    printf("%d\n", best);
    for (int i = 0; i < n; ++i)
        printf("%s\n", grid[i]);

    return 0;
}
