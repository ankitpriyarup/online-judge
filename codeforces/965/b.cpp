#include <cstdio>

using namespace std;

int n, k;
char grid[112][112];
int ways[112][112];

bool can_horiz(int i, int j) {
    if (j + k > n) return false;
    for (int d = 0; d < k; ++d) {
        if (grid[i][j + d] == '#')
            return false;
    }

    return true;
}

bool can_vert(int i, int j) {
    if (i + k > n) return false;
    for (int d = 0; d < k; ++d) {
        if (grid[i + d][j] == '#')
            return false;
    }

    return true;
}

int main() {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf(" %s", grid[i]);

    int ax = 0;
    int ay = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (can_horiz(i, j)) {
                for (int d = 0; d < k; ++d) {
                    ways[i][j + d]++;
                    if (ways[i][j + d] > ans) {
                        ax = i;
                        ay = j + d;
                        ans = ways[i][j + d];
                    }
                }
            }

            if (can_vert(i, j)) {
                for (int d = 0; d < k; ++d) {
                    ways[i + d][j]++;
                    if (ways[i + d][j] > ans) {
                        ax = i + d;
                        ay = j;
                        ans = ways[i + d][j];
                    }
                }
            }
        }
    }

    printf("%d %d\n", ax + 1, ay + 1);

    return 0;
}
