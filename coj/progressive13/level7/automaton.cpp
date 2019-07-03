#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 20;
constexpr int SIGMA = 30;
char c[SIGMA];
int inv_c[SIGMA];
int trans[MAXN][SIGMA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, s, k;
        cin >> n >> m >> s >> k;
        for (int i = 0; i < s; ++i) {
            cin >> c[i];
            inv_c[c[i] - 'a'] = i;
        }

        int acc_mask = 0;
        for (int i = 0; i < k; ++i) {
            int f;
            cin >> f;
            acc_mask |= (1 << f);
        }

        memset(trans, 0, sizeof(trans));
        for (int i = 0; i < m; ++i) {
            int u, v;
            char w;
            cin >> u >> v >> w;
            trans[u][inv_c[w - 'a']] |= (1 << v);
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            int mask = 1;
            string st;
            cin >> st;
            int len = st.size();
            for (int i = 0; i < len; ++i) {
                int w = inv_c[st[i] - 'a'];
                int new_mask = 0;
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j))
                        new_mask |= trans[j][w];
                }

                mask = new_mask;
            }

            if (mask & acc_mask) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    
    return 0;
}
