#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

string s;
int ans = 0;
set<tuple<ll, int, int>> memo;

bool dfs(ll mask, int p, int x, int y) {
    if (x < 0 or y < 0 or x >= 7 or y >= 7 or (mask & (1LL << (7LL * x + y)))) {
        return false;
    }
    if (memo.count(make_tuple(mask, x, y))) {
        cout << "USEFUL\n";
        return false;
    }
    if (p == 48) {
        if (x == 6 and y == 0) {
            ++ans;
            return true;
        }
        return false;
    }
    if (6 - x + y > 48 - p) {
        return false;
    }

    bool valid = false;
    ll new_mask = mask | (1LL << (7LL * x + y));
    if (s[p] == '?' or s[p] == 'L') {
        valid |= dfs(new_mask, p + 1, x, y - 1);
    }
    if (s[p] == '?' or s[p] == 'R') {
        valid |= dfs(new_mask, p + 1, x, y + 1);
    }
    if (s[p] == '?' or s[p] == 'U') {
        valid  |= dfs(new_mask, p + 1, x - 1, y);
    }
    if (s[p] == '?' or s[p] == 'D') {
        valid |= dfs(new_mask, p + 1, x + 1, y);
    }

    if (!valid) {
        memo.emplace(mask, x, y);
    }

    return valid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    dfs(0, 0, 0, 0);
    cout << ans << '\n';

    return 0;
}
