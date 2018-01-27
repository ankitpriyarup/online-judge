// DOES NOT WORK
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

constexpr int MAXN = 25;
constexpr int INF = 1e9;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, -1, 0, 1};

int n, m;
string grid[MAXN];
int sx, sy;
int gx, gy;
bool vis[MAXN][MAXN];

bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m and grid[x][y] != ' ';
}

ll ans;

struct state {
    pii me;
    vector<pii> popo;

    bool operator<(const state& other) const {
        return tie(me, popo) < tie(other.me, other.popo);
    }
};

bool is_popo(const vector<pii>& popo, int ignore, int x, int y) {
    for (int i = 0; i < popo.size(); ++i) {
        if (i == ignore) continue;

        if (x == popo[i].first and y == popo[i].second)
            return true;
    }

    return false;
}

int path(const pii& me, const vector<pii>& popo, int ignore, int x, int y) {
    if (is_popo(popo, ignore, x, y)) {
        return INF;
    }

    queue<pii> q;
    q.push({x, y});
    memset(vis, 0, sizeof(vis));
    vis[x][y] = true;
    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            pii cur = q.front();
            q.pop();

            if (cur.first == me.first and cur.second == me.second) {
                return lvl;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (in_bounds(nx, ny) and !vis[nx][ny] and !is_popo(popo, ignore, nx, ny)) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ++lvl;
    }

    return INF;
}

vector<pii> advance(const pii& me, const vector<pii>& popo) {
    int p = popo.size();
    vector<int> dists(p, INF + 1);
    vector<int> ds(p, 0);

    for (int i = 0; i < p; ++i) {
        for (int d = 0; d < 4; ++d) {
            int nx = popo[i].first + dx[d];
            int ny = popo[i].second + dy[d];
            if (!in_bounds(nx, ny)) continue;

            int cur_dist = path(me, popo, i, nx, ny);
            if (cur_dist < dists[i]) {
                dists[i] = cur_dist;
                ds[i] = d;
            }
        }
    }

    vector<pii> res(p);
    for (int i = 0; i < p; ++i) {
        cout << popo[i].first << ' ' << popo[i].second << ' ' << ds[i] << '\n';
        res[i] = {popo[i].first + dx[ds[i]], popo[i].second + dy[ds[i]]};
    }

    return res;
}

void print_state(const state& s) {
    cout << "ME: {" << s.me.first << ", " << s.me.second << "}\n";
    cout << "POLICE: {\n";
    for (const pii& p : s.popo) {
        cout << "\t" << p.first << ", " << p.second << '\n';
    }
    cout << "}\n\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool printed = false;
            if (s.me.first == i and s.me.second == j) {
                cout << 'L';
                printed = true;
            }

            for (const pii& p : s.popo) {
                if (p.first == i and p.second == j) {
                    cout << 'P';
                    printed = true;
                }
            }

            if (!printed) {
                cout << grid[i][j];
            }

        }
        cout << '\n';
    }
}

int bfs(const state& src) {
    queue<state> q;
    q.push(src);

    set<state> visited;
    visited.insert(src);

    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            state cur = q.front();
            q.pop();

            print_state(cur);

            if (cur.me.first == gx and cur.me.second == gy) {
                return lvl;
            }

            vector<pii> popos = advance(cur.me, cur.popo);
            bool bad = false;
            for (const pii& p : popos) {
                if (p.first == cur.me.first and p.second == cur.me.second) {
                    bad = true;
                    break;
                }
            }

            if (bad)
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = cur.me.first + dx[d];
                int ny = cur.me.second + dy[d];

                state bingo = {{nx, ny}, popos};
                if (in_bounds(nx, ny) and visited.find(bingo) == end(visited)) {
                    bool bad = false;

                    for (const pii& p : popos) {
                        if (p.first == nx and p.second == nx)
                            bad = true;
                    }

                    if (bad)
                        break;

                    visited.insert(bingo);
                    q.push(bingo);
                }
            }
        }

        ++lvl;
    }

    return INF;
}

int main() {
    cin >> n >> m;
    getline(cin, grid[0]);
    for (int i = 0; i < n; ++i) {
        getline(cin, grid[i]);
    }

    cin >> sx >> sy;
    cin >> gx >> gy;

    int p;
    cin >> p;
    vector<pii> police(p);
    for (int i = 0; i < p; ++i) {
        cin >> police[i].first >> police[i].second;
    }

    ans = bfs({{sx, sy}, police});

    if (ans == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}
