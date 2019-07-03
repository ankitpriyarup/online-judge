#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
constexpr int LOGN = 18;
int n;
int st[LOGN][MAXN];

int query(int a, int b) {
    if (a == b) return st[0][a];

    int k = LOGN - 1;
    while ((1 << k) >= b - a + 1) {
        --k;
    }

    // cout << a << " " << b << " " << k << '\n';
    int res = st[k][a] | st[k][b - (1 << k) + 1];
    // cout << "query(" << a << ", " << b << ") = " << res << '\n';
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> st[0][i];
        }
        for (int j = 0; j + 1 < LOGN; ++j) {
            for (int i = 0; i + (1 << (j + 1)) <= n; ++i) {
                st[j + 1][i] = st[j][i] | st[j][i + (1 << j)];
            }
        }

        set<int> vals;
        for (int i = 0; i < n; ++i) {
            int cur = st[0][i];
            int j = i;
            vals.insert(cur);
            while (query(i, n - 1) != cur) {
                int lo = j;
                int hi = n - 1;
                while (lo + 1 < hi) {
                    int mid = (lo + hi) >> 1;
                    if (query(i, mid) == cur) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }
                }

                j = hi;
                cur = query(i, j);
                vals.insert(cur);
            }

            vals.insert(query(i, n - 1));
        }

        cout << vals.size() << '\n';
    }
    
    return 0;
}
