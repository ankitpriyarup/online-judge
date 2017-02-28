#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXH = 18;
const int MAXN = (1 << 17) + 5;
const int INF = 1e9 + 7;
int h, k, n;
int a[MAXN];

// dp[i][j] = min number of bribes to get bear i to round j
int sparse[MAXN][MAXH];
int dp[MAXN][MAXH];
int opp[MAXH];

vector<int> tree[MAXN];

void merge(int node) {
    int lchild = 2 * node + 1;
    int rchild = 2 * node + 2;

    size_t aptr = 0;
    size_t bptr = 0;
    while (aptr < tree[lchild].size() and bptr < tree[rchild].size()) {
        if (a[tree[lchild][aptr]] < a[tree[rchild][bptr]]) {
            tree[node].push_back(tree[lchild][aptr++]);
        } else {
            tree[node].push_back(tree[rchild][bptr++]);
        }
    }

    while (aptr < tree[lchild].size()) {
        tree[node].push_back(tree[lchild][aptr++]);
    }

    while (bptr < tree[rchild].size()) {
        tree[node].push_back(tree[rchild][bptr++]);
    }
}

void build_tree(int node = 0, int l = 0, int r = n - 1) {
    tree[node].clear();
    if (l == r) {
        tree[node].push_back(l);
    } else {
        int mid = (l + r) >> 1;
        build_tree(2 * node + 1, l, mid);
        build_tree(2 * node + 2, mid + 1, r);

        merge(node);
    }
}

// find the index i such that a[i] is maximal and a[i] <= val
int query(int node, int l, int r, int ql, int qr, int val) {
    if (l == ql and r == qr) {
        // lo <= val
        // hi > val
        if (a[tree[node].back()] <= val) {
            return tree[node].back();
        } else if (a[tree[node][0]] > val) {
            return -1;
        } else {
            int lo = 0;
            int hi = tree[node].size() - 1;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (a[tree[node][mid]] <= val) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            return tree[node][lo];
        }
    } else {
        int ans = -1;
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            int cand = query(2 * node + 1, l, mid, ql, min(qr, mid), val);
            if (ans == -1 or (cand != -1 and a[ans] < a[cand])) {
                ans = cand;
            }
        }

        if (qr > mid) {
            int cand = query(2 * node + 2, mid + 1, r, max(mid + 1, ql), qr, val);
            if (ans == -1 or (cand != -1 and a[ans] < a[cand])) {
                ans = cand;
            }
        }

        return ans;
    }
}

void print_tree(int node) {
    if (!tree[node].size()) return;

    printf("%d: ", node);
    for (int x : tree[node]) {
        printf("%d ", x);
    }
    puts("");

    print_tree(2 * node + 1);
    print_tree(2 * node + 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d %d", &h, &k);
        n = (1 << h);

        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }

        build_tree();
        // print_tree(0);

        memset(dp, 0, sizeof(dp));
        for (int round = 1; round <= h; ++round) {
            int window_size = 1 << round;
            for (int i = 0; i < n; ++i) {
                int window_start = (i / window_size) * window_size;
                int window_mid = window_start + (window_size >> 1);

                dp[i][round] = INF;
                if (dp[i][round - 1] == INF) continue;
                int other_start = (i >= window_mid) ? window_start : window_mid;
                int other_end = (i >= window_mid) ? window_mid : (window_start + window_size);

                int best_opp = query(0, 0, n - 1, other_start, other_end - 1, a[i]);
                // printf("Best from %d to %d with val <= %d is index %d\n", other_start, other_end, a[i], best_opp);
                if (best_opp >= 0 and dp[best_opp][round - 1] != INF)
                    dp[i][round] = min(dp[i][round], dp[i][round - 1] + dp[best_opp][round - 1]);

                best_opp = query(0, 0, n - 1, other_start, other_end - 1, a[i] + k);
                // printf("Best from %d to %d with val <= %d is index %d\n", other_start, other_end, a[i] + k, best_opp);
                if (best_opp >= 0 and dp[best_opp][round - 1] != INF)
                    dp[i][round] = min(dp[i][round], dp[i][round - 1] + dp[best_opp][round - 1] + 1);
            }
        }

        printf("%d\n", dp[0][h] >= INF ? -1 : dp[0][h]);

    }
    return 0;
}
