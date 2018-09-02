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

constexpr int MAXN = 200005;
int n;
vector<int> tree[MAXN];

// is a == b[l, r), order no matter?
bool is_perm(const vector<int>& a, const vector<int>& b, int l, int r, int par) {
    // printf("PERM(%d, %d, %d)\n", l, r, par);
    vector<int> c(a.size());
    for (int i = l; i < r; ++i) {
        c[i - l] = b[i];
    }
    if (par)
        c[r - l] = par;

    sort(begin(c), end(c));

    /*
    printf("Left:\n");
    for (int x : a) {
        printf("%d ", x);
    }
    printf("\n");

    printf("Right:\n");
    for (int x : c) {
        printf("%d ", x);
    }
    printf("\n");
    */

    return a == c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(begin(tree[i]), end(tree[i]));
    }

    vector<int> bfs_out(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &bfs_out[i]);
    }

    if (bfs_out[0] != 1) {
        printf("No\n");
        return 0;
    }

    queue<pii> q;
    q.emplace(1, 0);

    int ptr = 1;
    while (!q.empty()) {
        int u, par;
        tie(u, par) = q.front();
        q.pop();

        // printf("U %d PAR %d\n", u, par);

        int block_sz = tree[u].size() - (par != 0);
        // the next bsz elements should be children of par in some order
        if (!is_perm(tree[u], bfs_out, ptr, ptr + block_sz, par)) {
            printf("No\n");
            return 0;
        }

        for (int i = ptr; i < ptr + block_sz; ++i) {
            q.emplace(bfs_out[i], u);
        }
        ptr += block_sz;
    }

    printf("Yes\n");
    return 0;
}
