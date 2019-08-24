#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
int f_tree[MAXN];

int query(int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

inline int query(int l, int r) {
    return query(r) - query(l - 1);
}

void update(int x, int v) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

inline bool isvowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (isvowel(s[i])) {
                update(i + 1, 1);
            }
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            char op;
            int x, y;
            char nc;
            cin >> op >> x;
            if (op == 'F') {
                cin >> y;
                cout << query(x, y) << '\n';
            } else {
                cin >> nc;
                if (isvowel(s[x - 1]))
                    update(x, -1);
                s[x - 1] = nc;
                if (isvowel(nc)) {
                    update(x, 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isvowel(s[i])) {
                update(i + 1, -1);
            }
        }
    }
    
    return 0;
}
