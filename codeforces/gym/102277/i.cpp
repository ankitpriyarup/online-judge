#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n;
string s;
int need[10];

constexpr int MAXM = 30;
int m;
string a[MAXM];
map<pair<int, int>, bool> memo;

bool solve(int mask, int idx) {
    if (idx >= n) {
        return true;
    }

    pii state = make_pair(mask, idx);
    auto it = memo.find(state);
    if (it != end(memo))
        return it->second;

    bool res = false;
    for (int i = 0; i <= m; ++i) {
        if (mask & (1 << i)) continue;
        int k = a[i].size();
        if (idx + k <= n and s.substr(idx, k) == a[i] and solve(mask | (1 << i), idx + k)) {
            res = true;
            break;
        }
    }

    return memo[state] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();

    for (char c : s) {
        ++need[c - '0'];
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        for (char c : a[i])
            --need[c - '0'];
    }

    for (int i = 1; i < 100; ++i) {
        a[m] = to_string(i);

        for (char c : a[m]) {
            --need[c - '0'];
        }
        bool valid = true;
        for (int k = 0; k < 10; ++k) {
            if (need[k] > 0) {
                valid = false;
                break;
            }
        }
        for (char c : a[m]) {
            ++need[c - '0'];
        }
        if (!valid) {
            continue;
        }

        // cout << "trying " << a[m] << '\n';

        memo.clear();
        if (solve(0, 0)) {
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}
