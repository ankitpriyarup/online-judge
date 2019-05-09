#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n;
int v[7];
int type[MAXN];
int f_tree[7][MAXN];

int query(int k, int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += f_tree[k][x];
    }

    return res;
}

int query(int k, int l, int r) {
    return query(k, r) - query(k, l - 1);
}

void update(int k, int x, int d) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[k][x] += d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= 6; ++i) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        type[i + 1] = s[i] - '0';
        update(type[i + 1], i + 1, 1);
    }

    while (q-- > 0) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, p;
            cin >> k >> p;
            update(type[k], k, -1);
            type[k] = p;
            update(type[k], k, 1);
        } else if (op == 2) {
            int p, vv;
            cin >> p >> vv;
            v[p] = vv;
        } else {
            ll res = 0LL;
            int l, r;
            cin >> l >> r;
            for (int i = 1; i <= 6; ++i) {
                int cur = query(i, l, r);
                res += 1LL * cur * v[i];
            }

            cout << res << '\n';
        }
    }
    
    return 0;
}
