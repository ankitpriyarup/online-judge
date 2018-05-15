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

constexpr int MAXN = 33;
int l, w, n, r;
int x[MAXN], y[MAXN];
int wx[4], wy[4];
bool match[MAXN][4];
bool has_match[4];

int dist2(int a, int b, int c, int d) {
    int dx = a - c;
    int dy = b - d;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d %d", &l, &w, &n, &r);
    r *= 2;
    wx[0] = -l;
    wy[0] = 0;

    wx[1] = l;
    wy[1] = 0;

    wx[2] = 0;
    wy[2] = -w;

    wx[3] = 0;
    wy[3] = w;

    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &x[i], &y[i]);
        x[i] *= 2;
        y[i] *= 2;
        for (int j = 0; j < 4; ++j) {
            match[i][j] = dist2(x[i], y[i], wx[j], wy[j]) <= r * r;
            has_match[j] |= match[i][j];
        }
    }

    bool can_cover = true;
    for (int j = 0; j < 4; ++j) {
        can_cover &= has_match[j];
    }

    if (!can_cover) {
        printf("Impossible\n");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int matches = 0;
        for (int j = 0; j < 4; ++j) {
            matches += match[i][j];
        }
        if (matches == 4) {
            printf("%d\n", 1);
            return 0;
        }
    }

    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            int matches = 0;
            for (int j = 0; j < 4; ++j) {
                matches += match[a][j] or match[b][j];
            }

            if (matches == 4) {
                printf("%d\n", 2);
                return 0;
            }
        }
    }

    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            for (int c = b + 1; c < n; ++c) {
                int matches = 0;
                for (int j = 0; j < 4; ++j) {
                    matches += match[a][j] or match[b][j] or match[c][j];
                }

                if (matches == 4) {
                    printf("%d\n", 3);
                    return 0;
                }
            }
        }
    }

    printf("%d\n", 4);
    return 0;
}
