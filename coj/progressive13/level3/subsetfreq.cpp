#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 6;
int n, k;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    vector<pii> res;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int r = n - 1;
        int ans = 0;
        for (int l = 0; l < r; ++l) {
            while (l < r and a[l] + a[r] > x) {
                --r;
            }
            if (l < r and a[l] + a[r] == x) {
                ++ans;
            }
        }

        res.emplace_back(-ans, x);
    }

    sort(all(res));
    for (auto& p : res) {
        cout << p.second << ' ' << -p.first << '\n';
    }
    
    return 0;
}
