#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int INF = 1e9;
int grid[12][12];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char moves[] = "DRUL";
// char moves[] = "ULDR";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    grid[2][2] = 1;
    grid[2][9] = 1;
    grid[9][2] = 1;
    grid[9][9] = 1;

    grid[5][5] = 2;
    grid[5][6] = 2;
    grid[6][5] = 2;
    grid[6][6] = 2;

    grid[8][1] = 2;
    grid[9][1] = 2;
    grid[8][2] = 2;

    grid[8][9] = 2;
    grid[9][10] = 2;
    grid[8][10] = 2;

    int T;
    cin >> T;
    while (T-- > 0) {
        int sx, sy;
        cin >> sx >> sy;
        --sx; --sy;

        vector<vi> dist(12, vi(12, INF));
        vector<vi> previous(12, vi(12));
        queue<pii> q;
        q.emplace(sx, sy);
        dist[sx][sy] = 0;

        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (0 <= nx and nx < 12 and 0 <= ny and ny < 12) {
                    if (dist[nx][ny] > dist[x][y] + 1 and grid[nx][ny] != 2) {
                        dist[nx][ny] = dist[x][y] + 1;
                        previous[nx][ny] = d;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        int x = 2;
        int y = 2;
        string ans;
        while (x != sx or y != sy) {
            int d = previous[x][y];
            ans.push_back(moves[d]);
            x -= dx[d];
            y -= dy[d];
        }

        reverse(all(ans));

        cout << ans.size() << '\n';
        cout << ans << '\n';
    }

    return 0;
}
