#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXR = 1000;
constexpr int MAXC = 4000;
char grid[MAXR][MAXC];
char moves[] = "_/\\_/\\";

// always the lower left corner
vector<pii> pos;
int dir = 0;
int maxx, maxy;

int dx[] = {0, 1, 1, 0, -1, -1};
int dy[] = {1, 1, -1, -1, -1,  1};

int px[] = {0, 0, 0, 0, -1, -1};
int py[] = {0, 0, -1, -1, -1, 0};

/*
 * 0 0 | dir = 0
 * 0 1 | dir = 1
 * 1 2 | dir = 5
 * 0 3 | dir = 0
 * 0 4 |
 */
void f(int v) {
    if (v == 0) {
        int x = pos.back().first;
        int y = pos.back().second;

        if (grid[x + px[dir]][y + py[dir]] != '.')
            --y;
        grid[x + px[dir]][y + py[dir]] = moves[dir];
        x += dx[dir];
        y += dy[dir];

        maxx = max(maxx, x);
        maxy = max(maxx, y);

        pos.emplace_back(x, y);
        return;
    }

    f(v - 1);
    dir = (dir + 1) % 6;
    f(v - 1);
    dir = (dir + 5 + 5) % 6;
    f(v - 1);
    dir = (dir + 1) % 6;
    f(v - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    bool first = true;
    while (cin >> n) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        if (!n) {
            cout << "_\n";
            continue;
        }
        memset(grid, '.', sizeof(grid));
        pos.clear();
        pos.emplace_back(0, 0);
        dir = 0;

        maxx = 0;
        maxy = 0;
        f(n);

        for (int i = maxx - 1; i >= 0; --i) {
            grid[i][maxy] = '\0';
            cout << grid[i] << '\n';
        }
    }
    
    return 0;
}
