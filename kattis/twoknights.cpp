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

char upper[5][11] = {"QWERTYUIOP", "ASDFGHJKL:", "ZXCVBNM<>?", "--      --"};
char lower[5][11] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./", "--      --"};
char s[122];
bool _vis[5][11][5][11][122];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

char getchar(int x1, int y1, int x2, int y2) {
    if (lower[x2][y2] == '-')
        return upper[x1][y1];
    else
        return lower[x1][y1];
}

struct state {
    int x1, y1, x2, y2, p;

    vector<state> follow() {
        vector<state> res;
        for (int d = 0; d < 8; ++d) {
            int nx = x1 + dx[d];
            int ny = y1 + dy[d];
            if (0 <= nx and nx < 4 and 0 <= ny and ny < 10 and !(nx == x2 and ny == y2)) {
                state nxt{nx, ny, x2, y2, p};
                char c = getchar(nx, ny, x2, y2);
                if (c == '-') {
                    res.push_back(nxt);
                } else if (c == s[p]) {
                    nxt.p += 1;
                    res.push_back(nxt);
                }
            }

            nx = x2 + dx[d];
            ny = y2 + dy[d];
            if (0 <= nx and nx < 4 and 0 <= ny and ny < 10 and !(nx == x1 and ny == y1)) {
                state nxt{x1, y1, nx, ny, p};
                char c = getchar(nx, ny, x1, y1);

                if (c == '-') {
                    res.push_back(nxt);
                } else if (c == s[p]) {
                    nxt.p += 1;
                    res.push_back(nxt);
                }
            }
        }

        return res;
    }
};

bool vis(const state& sta) {
    return _vis[sta.x1][sta.y1][sta.x2][sta.y2][sta.p];
}

void set_vis(const state& sta) {
    _vis[sta.x1][sta.y1][sta.x2][sta.y2][sta.p] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while (true) {
        gets(s);
        if (s[0] == '*') break;

        // printf("%s: ", s);

        int n = strlen(s);
        memset(_vis, 0, sizeof(_vis));
        queue<state> q;
        q.push({3, 0, 3, 9, 0});
        set_vis(q.front());

        bool poss = false;
        while (!q.empty()) {
            state cur = q.front();
            q.pop();

            if (cur.p == n) {
                poss = true;
                break;
            }

            for (auto& s2 : cur.follow()) {
                if (!vis(s2)) {
                    set_vis(s2);
                    q.push(s2);
                }
            }
        }

        printf("%d\n", poss);
    }

    return 0;
}
