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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, k;
    scanf(" %d %d", &r, &k);
    int mid = 2 * r - 1;
    vector<vector<int>> ids(mid + 2, vector<int>(mid + 2));
    int width = r;
    int dd = 1;
    int start = 1;
    int next_id = 1;
    vector<pii> rev(r * r * r);
    for (int i = 1; i <= mid; ++i) {
        for (int j = 0; j < width; ++j) {
            ids[i][start + j] = next_id++;
            rev[ids[i][start + j]] = {i, start + j};
        }

        width += dd;
        if (dd < 0)
            start -= dd;
        if (width == 2 * r) {
            width -= 2;
            dd = -1;
            start = 2;
        }
    }
    
    /*
    for (int i = 0; i <= mid + 1; ++i) {
        for (int j = 0; j <= mid + 1; ++j) {
            cout << ids[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    vector<vector<char>> active(mid + 2, vector<char>(mid + 2, 0));
    int v, x, y;
    while (k-- > 0) {
        scanf(" %d", &v);
        tie(x, y) = rev[v];
        active[x][y] = true;
    }
    vector<vector<vector<char>>> vis(mid + 2, vector<vector<char>>(mid + 2, vector<char>(6, 0)));
    queue<pii> q;
    q.emplace(0, 0);
    vector<int> dx = {1, 0, -1, 0, 1, -1};
    vector<int> dy = {0, 1, 0, -1, 1, -1};
    int ans = 0;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 6; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < mid + 2 and 0 <= ny and ny < mid + 2 and !vis[nx][ny][d]) {
                vis[nx][ny][d] = true;
                if (active[nx][ny]) {
                    ++ans;
                } else {
                    q.emplace(nx, ny);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
