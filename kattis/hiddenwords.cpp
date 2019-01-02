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

constexpr int MAXN = 13;
int n, m;
string grid[MAXN];
bool vis[MAXN][MAXN];

string word;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool dfs(int k, int x, int y) {
    if (k == word.size())
        return true;

    bool res = false;

    vis[x][y] = true;

    for (int d = 0; !res and d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx and nx < n and 0 <= ny and ny < m and !vis[nx][ny] and grid[nx][ny] == word[k]) {
            res |= dfs(k + 1, nx, ny);
        }
    }

    vis[x][y] = false;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<vector<pii>> starts(26);
    vector<vector<bool>> adj(26, vector<bool>(26, false));
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = grid[i][j] - 'A';
            starts[x].emplace_back(i, j);

            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    int y = grid[nx][ny] - 'A';
                    adj[x][y] = adj[y][x] = true;
                }
            }
        }
    }

    int q;
    cin >> q;
    int ans = 0;
    while (q-- > 0) {
        cin >> word;

        bool poss = true;
        for (int i = 1; i < word.size(); ++i) {
            if (starts[word[i] - 'A'].empty() || !adj[word[i] - 'A'][word[i - 1] - 'A']) {
                poss = false;
                break;
            }
        }

        if (!poss)
            continue;

        bool found = false;
        for (auto& p : starts[word[0] - 'A']) {
            if (dfs(1, p.first, p.second)) {
                found = true;
                break;
            }
        }

        ans += found;
    }
    
    cout << ans << '\n';

    return 0;
}
