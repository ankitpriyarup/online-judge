/*
USER: rednano1
PROG: starry
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 102;

const int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};
const int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

int n, m;
char grid[MAXN][MAXN];
// 0 unvisit, 1 complete, 2 temp
int visit[MAXN][MAXN];

int top, bot, leftt, rightt;

void dfs(int x, int y) {
    top = min(top, x);
    bot = max(bot, x);
    leftt = min(leftt, y);
    rightt = max(rightt, y);

    visit[x][y] = 2;

    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (0 <= nx and nx < n
        and 0 <= ny and ny < m
        and visit[nx][ny] == 0
        and grid[nx][ny] == '1') {
            dfs(nx, ny);
        }
    }
}

vector<vector<bool> > rotate(vector<vector<bool> >& state) {
    vector<vector<bool> > rotated(state[0].size(), vector<bool>(state.size()));
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state[0].size(); ++j) {
            rotated[state[0].size() - j - 1][i] = state[i][j];
        }
    }

    return rotated;
}

void print_state(vector<vector<bool> >& state) {
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state[i].size(); ++j) {
            printf("%c", state[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}


void reflect(vector<vector<bool> >& state) {
    for (int i = 0; i < state.size(); ++i) {
        int start = 0;
        int end = state[0].size() - 1;
        while (start < end) {
            swap(state[i][start], state[i][end]);
            ++start;
            --end;
        }
    }
}

vector<vector<bool> > normalize(vector<vector<bool> >& state) {
    vector<vector<bool> > ans = state;
    vector<vector<bool> > cur = state;

    for (int i = 0; i < 4; ++i) {
        cur = rotate(cur);
        ans = min(ans, cur);

        reflect(cur);
        ans = min(ans, cur);

        reflect(cur);
    }

    return ans;
}

map<vector<vector<bool> >, char> all;

void fill_thing(int top, int leftt, vector<vector<bool> >& state, char c) {
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state[i].size(); ++j) {
            if (visit[i + top][j + leftt] == 2) {
                grid[i + top][j + leftt] = c;
                visit[i + top][j + leftt] = 1;
            }
        }
    }
}

int main() {
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; ++i){
        scanf("%s", grid[i]);
    }

    memset(visit, 0, sizeof(visit));
    char next_char = 'a';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1' and visit[i][j] == 0) {
                top = leftt = n + m;
                bot = rightt = -1;
                dfs(i, j);

                vector<vector<bool> > state(bot - top + 1, vector<bool>(rightt - leftt + 1));
                for (int i = top; i <= bot; ++i) {
                    for (int j = leftt; j <= rightt; ++j) {
                        state[i - top][j - leftt] = (visit[i][j] == 2);
                    }
                }

                vector<vector<bool> > canon = normalize(state);

                if (all.find(canon) == all.end()) {
                    all[canon] = next_char++;
                }

                fill_thing(top, leftt, state, all[canon]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
