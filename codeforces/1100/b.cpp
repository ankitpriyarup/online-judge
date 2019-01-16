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

    int n, m;
    cin >> n >> m;

    vi a(m);
    vector<vi> occ(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]].push_back(i);
    }

    int cap = m + m;
    for (int i = 0; i < n; ++i)
        cap = min(cap, (int)occ[i].size());

    // for every i from 1 to cap (inclusive), see when it is met
    string s(m, '0');
    for (int i = 0; i < cap; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            x = max(x, occ[j][i]);
        }

        s[x] = '1';
    }
    
    cout << s << '\n';
    return 0;
}
