#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1000001;
int n;
int a[MAXN], b[MAXN];
int f_tree[MAXN];

int query(int x) {
    int res = 0;
    for (x += 1; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

void update(int x, int v) {
    for (x += 1; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        if (!n) break;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int m = unique(b, b + n) - b;

        memset(f_tree, 0, sizeof(f_tree));
        ll ans = 0LL;
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(b, b + m, a[i]) - b;
            ans += i - query(x);
            update(x, 1);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
