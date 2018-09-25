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

string solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<string> grid(n), pattern(a);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < a; ++i) {
        cin >> pattern[i];
    }

    int sx = -1;
    int sy = -1;
    vector<pii> delta;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (pattern[i][j] == '.') continue;
            if (delta.empty()) {
                delta.emplace_back(0, 0);
                sx = i;
                sy = j;
            } else {
                delta.emplace_back(i - sx, j - sy);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') continue;
            for (pii& p : delta) {
                int nx = i + p.first;
                int ny = j + p.second;
                if (nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] != 'x') {
                    return "NIE";
                }

                grid[nx][ny] = '.';
            }
        }
    }

    return "TAK";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        cout << solve() << '\n';
    }
    
    return 0;
}
