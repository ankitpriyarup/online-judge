#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 300005;
int n;
pii a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);

    ll delta = 0;
    vector<pair<ll, int>> stk;
    vector<tuple<int, int, ll>> moves;
    for (int i = 0; i < n; ++i) {
        ll x = a[i].first - b[i].first;
        delta += x;

        while (x > 0 and !stk.empty()) {
            ll take = min(x, stk.back().first);
            x -= take;
            moves.emplace_back(stk.back().second, a[i].second, take);
            stk.back().first -= take;
            if (stk.back().first == 0) {
                stk.pop_back();
            }
        }
        if (x > 0) {
            cout << "NO\n";
            return 0;
        }
        if (x < 0) {
            stk.emplace_back(-x, a[i].second);
        }
    }

    if (delta != 0 or !stk.empty()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << moves.size() << '\n';
    for (auto& m : moves) {
        int x, y; ll d;
        tie(x, y, d) = m;
        cout << (x + 1) << ' ' << (y + 1) << ' ' << d << '\n';
    }

    /**
     * 2 2 4 7 9
     * 4 5 5 5 5
     * +2 +3 +1 -2 -4
     *
     * 4
4 3 1
2 3 1
2 5 2
1 5 2

2 2 7 4 9
2 2 6 5 9
2 3 5 5 9
2 5 5 5 7
4 5 5 5 5 
     *
     * 5 10 15 20
     * 7 8 17 18
     * +2 -2 +2 -2
     *
     */
    
    return 0;
}
