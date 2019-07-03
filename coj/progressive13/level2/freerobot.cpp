#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 16;
bool vis[MAXN][MAXN];
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {-1, 1, 0, -1, 1, 0, -1, 1};

int solve(int x, int y, int m) {
    if (m == 0) {
        return 1;
    }

    int ans = 0;
    vis[x][y] = true;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx and 0 <= ny and !vis[nx][ny]) {
            ans += solve(nx, ny, m - 1);
        }
    }
    vis[x][y] = false;

    return ans;
}

ll res[] = {1, 3, 15, 75, 391, 2065, 11091, 60215, 330003, 1820869, 10103153, 56313047, 315071801, 1768489771, 9953853677, 56158682949, 317505199769, 1798402412539};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;

        cout << res[n] << '\n';
    }

    return 0;
}
