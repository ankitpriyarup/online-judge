#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
constexpr int vowels[] = {0, 4, 8, 14, 20};
int n;
int tree[4 * MAXN][26];
int lazy[4 * MAXN];

int temp[26];
void push(int node) {
    if (!lazy[node]) return;
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    memcpy(temp, tree[node], sizeof(temp));
    for (int k = 0; k < 26; ++k) {
        tree[node][k] = temp[(k + lazy[node]) % 26];
    }

    lazy[node] = 0;
}

void pull(int node) {
    for (int k = 0; k < 26; ++k) {
        tree[node][k] = tree[2 * node][(k + lazy[2 * node]) % 26] + tree[2 * node + 1][(k + lazy[2 * node + 1]) % 26];
    }
}

void build(int node, int l, int r, const string& s) {
    lazy[node] = 0;
    if (l == r) {
        memset(tree[node], 0, sizeof(tree[node]));
        tree[node][s[l] - 'a'] = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * node, l, mid, s);
    build(2 * node + 1, mid + 1, r, s);

    pull(node);
}

int query(int node, int l, int r, int ql, int qr) {
    // printf("query(%d, %d, %d, %d, %d)\n", node, l, r, ql, qr);
    if (r < ql or qr < l) {
        return 0;
    }

    if (ql <= l and r <= qr) {
        // cout << "at node which covers range " << l << " to " << r << '\n';
        // cout << "lazy = " << lazy[node] << '\n';
        /*
        for (int k = 0; k < 26; ++k) {
            cout << tree[node][k] << ' ';
        }
        cout << '\n';
        */
        
        int ans = 0;
        for (int x : vowels) {
            ans += tree[node][(x + lazy[node]) % 26];
        }

        return ans;
    }

    push(node);

    int mid = (l + r) / 2;
    int ans = query(2 * node, l, mid, ql, qr) +
        query(2 * node + 1, mid + 1, r, ql, qr);

    pull(node);

    return ans;
}

int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

void update(int node, int l, int r, int ql, int qr, int v) {
    // printf("update(%d, %d, %d, %d, %d, %d)\n", node, l, r, ql, qr, v);
    if (r < ql or qr < l) {
        return;
    }

    if (ql <= l and r <= qr) {
        lazy[node] += v;
        return;
    }

    push(node);
    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr, v);
    update(2 * node + 1, mid + 1, r, ql, qr, v);
    pull(node);
}

void update(int l, int r, int v) {
    update(1, 0, n - 1, l, r, v);
}

void solve() {
    string s;
    cin >> s;
    n = s.size();

    build(1, 0, n - 1, s);

    int q;
    cin >> q;
    while (q-- > 0) {
        char op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        --l; --r;

        if (op == 'F') {
            int ans = query(l, r);
            cout << ans << '\n';
        } else {
            int v;
            cin >> v;
            v = 26 - (v % 26);

            update(l, r, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
