#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n;
int p[2][MAXN];
int inv[MAXN];
int f_tree[MAXN];

int query(int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res = max(res, f_tree[x]);
    }
    return res;
}

void update(int x, int v) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] = max(f_tree[x], v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i <= n; ++i) {
            cin >> p[k][i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        inv[p[0][i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        p[1][i] = inv[p[1][i]];
    }

    // find LCS of two permutations
    // rewrite the second perm in terms of the first
    // now its find the largest increasing subsequence
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 1 + query(p[1][i]);
        update(p[1][i], cur);
        ans = max(ans, cur);
    }

    cout << 2 << ' ' << (ans + 1) << '\n';
    
    return 0;
}
