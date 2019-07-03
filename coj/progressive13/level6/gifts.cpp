#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 500005;
map<int, int> last;
int a[MAXN];
vector<tuple<int, int, int>> queries[MAXN];
int ans[MAXN];

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

    int n;
    while (cin >> n) {
        last.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            queries[i].clear();
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int l, r, k;
            cin >> l >> r >> k;

            --l; --r;
            queries[r].emplace_back(l, k, i);
        }

        memset(f_tree, 0, sizeof(f_tree));
        for (int r = 0; r < n; ++r) {
            if (last.count(a[r]))
                update(last[a[r]], -1);
            last[a[r]] = r;
            update(r, 1);

            for (auto& qq : queries[r]) {
                int l, k, idx;
                tie(l, k, idx) = qq;

                int bap = query(l - 1);
                if (query(l) - bap == k) {
                    ans[idx] = l;
                } else if (query(r) - bap < k) {
                    ans[idx] = -1;
                } else {
                    int lo = l;
                    int hi = r;
                    while (lo + 1 < hi) {
                        int mid = (lo + hi) >> 1;
                        if (query(mid) - bap < k) {
                            lo = mid;
                        } else {
                            hi = mid;
                        }
                    }

                    ans[idx] = hi;
                }
            }
        }

        for (int i = 0; i < q; ++i) {
            if (ans[i] == -1) {
                cout << ":(\n";
            } else {
                cout << a[ans[i]] << '\n';
            }
        }
    }
    
    return 0;
}
