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
using vi = vector<int>;

constexpr int MAXN = 102;
int r, c;
char rows[MAXN], cols[MAXN];
char grid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %s", rows);
    scanf(" %s", cols);
    r = strlen(rows);
    c = strlen(cols);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            grid[i][j] = '1';
        }
        grid[i][c] = '\0';
    }

    int roff = 0;
    int coff = 0;
    queue<int> rq, cq;
    for (int i = 0; i < r; ++i) {
        if (rows[i] - '0' != (c % 2)) {
            ++roff;
            rq.push(i);
        }
    }

    for (int j = 0; j < c; ++j) {
        if (cols[j] - '0' != (r % 2)) {
            ++coff;
            cq.push(j);
        }
    }

    int rc = min(roff, coff);
    if ((roff - rc) % 2 != 0 || (coff - rc) % 2 != 0) {
        printf("%d\n", -1);
        return 0;
    }
    while (roff > rc) {
        int a = rq.front();
        rq.pop();
        int b = rq.front();
        rq.pop();

        grid[a][0] = '0';
        grid[b][0] = '0';
        roff -= 2;
    }
    while (coff > rc) {
        int a = cq.front();
        cq.pop();
        int b = cq.front();
        cq.pop();

        grid[0][a] = '0';
        grid[0][b] = '0';
        coff -= 2;
    }

    if (roff != coff) {
        printf("%d\n", -1);
        return 0;
    }

    while (roff > 0) {
        int a = rq.front();
        rq.pop();
        int b = cq.front();

        cq.pop();
        grid[a][b] = '0';

        --roff;
        --coff;
    }

    for (int i = 0; i < r; ++i) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
