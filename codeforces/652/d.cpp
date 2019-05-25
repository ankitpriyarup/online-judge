#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(r, l, i);
    }
    sort(all(a));

    vi ans(n);
    int tot = 0;
    map<ll, int> bit;
    constexpr int OFFSET = 1e9 + 9;
    for (auto& t : a) {
        int l, r, idx;
        tie(r, l, idx) = t;
        ans[idx] = tot;
        ll x = OFFSET + l;
        while (x > 0) {
            ans[idx] -= bit[x];
            x -= (x & -x);
        }

        ++tot;
        x = OFFSET + l;
        while (x < OFFSET + OFFSET) {
            bit[x]++;
            x += (x & -x);
        }
    }

    for (int x : ans) {
        cout << x << '\n';
    }
    
    return 0;
}
