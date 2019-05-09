#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int find(vi& uf, int u) {
    return uf[u] = uf[u] == u ? u : find(uf, uf[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<deque<char>> s(n);
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;

        for (char c : t) {
            s[i].push_back(c);
        }
    }

    vi uf(n);
    iota(all(uf), 0);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int ur = find(uf, u);
        int vr = find(uf, v);

        if (s[ur].size() >= s[vr].size()) {
            for (char c : s[vr]) {
                s[ur].push_back(c);
            }
            s[vr].clear();

            uf[vr] = ur;
        } else {
            for (int j = static_cast<int>(s[ur].size()) - 1; j >= 0; --j) {
                s[vr].push_front(s[ur][j]);
            }
            s[ur].clear();

            uf[ur] = vr;
        }
    }

    string res;
    int idx = find(uf, 0);
    for (char c : s[idx]) {
        res.push_back(c);
    }
    cout << res << '\n';
    
    return 0;
}
