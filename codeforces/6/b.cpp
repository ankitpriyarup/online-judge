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

int n, m;
char src[5];
char grid[300][300];
int freq[300];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %s", &n, &m, src);
    for (int i = 0; i < n; ++i) {
            scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == src[0]) {
                for (int d = 0; d < 4; ++d) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                        ++freq[grid[nx][ny]];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int c = 'A'; c <= 'Z'; ++c) {
        if (c == src[0]) continue;
        if (freq[c] > 0) ++ans;
    }

    printf("%d\n", ans);

    return 0;
}
