#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 10004;
int r, c;
char grid[MAXN][MAXN];

bool bad_row[MAXN];
bool bad_col[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(bad_row, false, sizeof(bad_row));
    memset(bad_col, false, sizeof(bad_col));

    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        scanf("%s", grid[i]);

        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'X') {
                bad_row[i] = true;
                bad_col[j] = true;
            }
        }
    }

    int q, qc, qr;
    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%d %d", &qc, &qr);
        --qc; --qr;
        if (bad_row[qr] or bad_row[qc]) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
