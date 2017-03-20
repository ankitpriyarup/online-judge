#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 51;
const int BOUND = 25;

int adj[MAXN][MAXN];

// number of triangles in this subgraph
// two of them to handle differing offsets
int dp[2][1 << BOUND];

inline int set(const int& mask, const int& i, const int& offset) {
    return mask & (1 << (i - offset));
}

inline int without(const int& mask, const int& i, const int& offset) {
    return mask & ~(1 << (i - offset));
}

void print_mask(const int& mask, const int& start, const int& end) {
    const int count = __builtin_popcount(mask);

    printf("%d\n", count);
    for (int i = start; i <= end; ++i) {
        if (set(mask, i, start)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int brute_force(const int& start, const int& end, const int dp_ind, int& tri_count, int& num_nodes) {
    tri_count = 0;
    num_nodes = 1;
    int best_mask = 1;

    for (int mask = 7; mask < (1 << (end - start + 1)); ++mask) {
        const int cur_nodes = __builtin_popcount(mask);
        if (cur_nodes < 3)
            continue;

        int i = start;

        while (!set(mask, i, start))
            ++i;

        dp[dp_ind][mask] = dp[dp_ind][without(mask, i, start)];

        for (int j = i + 1; j <= end; ++j) {
            if (!set(mask, j, start)) continue;
            for (int k = j + 1; k <= end; ++k) {
                if (!set(mask, k, start)) continue;

                if (adj[i][j] and adj[i][k] and adj[j][k])
                    ++dp[dp_ind][mask];
            }
        }

        const int cur_tri = dp[dp_ind][mask];
        // update if num_tri / num_nodes < cur_tri / cur_nodes
        // update if num_tri * cur_nodes < cur_tri * num_nodes
        if (tri_count * cur_nodes < cur_tri * num_nodes) {
            tri_count = cur_tri;
            num_nodes = cur_nodes;
            best_mask = mask;
        }
    }

    return best_mask;
}

/*
int tri[MAXN];
void heuristic(const int& n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (adj[i][j] and adj[i][k] and adj[j][k]) {
                    ++tri[i];
                    ++tri[j];
                    ++tri[k];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (tri[i]) ++ans;
    }

    if (ans == 0) {
        ans = 1;
        tri[1] = 1;
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        if (tri[i]) printf("%d ", i);
    }
}
*/

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }

    int t1, t2;
    int c1, c2;
    if (n <= BOUND) {
        int m = brute_force(1, n, 0, t1, c1);

        print_mask(m, 1, n);
    } else {
        int m1 = brute_force(1, BOUND, 0, t1, c1);
        int m2 = brute_force(BOUND + 1, n, 0, t2, c2);

        // t1 / c1 < t2 / c2
        if (t1 * c2 < t2 * c1) {
            print_mask(m2, BOUND + 1, n);
        } else {
            print_mask(m1, 1, BOUND);
        }
    }

    return 0;
}
