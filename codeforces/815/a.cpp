#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 505;
int n, m;
int g[MAXN][MAXN];

int moves = 0;
vector<pair<int, int> > row_out, col_out;

void do_rows() {
    for (int i = 0; i < n; ++i) {
        int v = MAXN;
        for (int j = 0; j < m; ++j) {
            v = min(v, g[i][j]);
        }

        if (v) {
            row_out.push_back(make_pair(i, v));
            moves += v;
            for (int j = 0; j < m; ++j) {
                g[i][j] -= v;
            }
        }
    }
}

void do_cols() {
    for (int j = 0; j < m; ++j) {
        int v = MAXN;
        for (int i = 0; i < n; ++i) {
            v = min(v, g[i][j]);
        }

        if (v) {
            col_out.push_back(make_pair(j, v));
            moves += v;
            for (int i = 0; i < n; ++i) {
                g[i][j] -= v;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &g[i][j]);
        }
    }

    if (n < m) {
        do_rows();
        do_cols();
    } else {
        do_cols();
        do_rows();
    }

    bool solved = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            solved &= (g[i][j] == 0);
        }
    }

    if (!solved) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", moves);
        for (pair<int, int> rd : row_out) {
            int ind = rd.first;
            int rep = rd.second;
            while (rep-- > 0) {
                printf("row %d\n", ind + 1);
            }
        }

        for (pair<int, int> cd : col_out) {
            int ind = cd.first;
            int rep = cd.second;
            while (rep-- > 0) {
                printf("col %d\n", ind + 1);
            }
        }
    }

    return 0;
}
