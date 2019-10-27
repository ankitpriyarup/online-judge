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

    int n, k;
    cin >> n >> k;
    vector<vector<string>> prefs(n);
    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;
        prefs[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> prefs[i][j];
        }
    }

    int p;
    cin >> p;
    vector<string> names(p);
    for (auto& name : names) {
        cin >> name;
    }

    vi pref_ptrs(n, 0);
    int name_ptr = 0;

    set<string> taken;
    vector<vector<string>> ans(n);
    for (int round = 0; round < k; ++round) {
        for (int i = 0; i < n; ++i) {
            while (pref_ptrs[i] < prefs[i].size() and taken.count(prefs[i][pref_ptrs[i]])) {
                ++pref_ptrs[i];
            }

            while (name_ptr < p and taken.count(names[name_ptr])) {
                ++name_ptr;
            }

            if (pref_ptrs[i] < prefs[i].size()) {
                ans[i].push_back(prefs[i][pref_ptrs[i]++]);
            } else {
                ans[i].push_back(names[name_ptr++]);
            }
            taken.insert(ans[i].back());
        }
    }

    for (int i = 0; i < n; ++i) {
        for (auto& player : ans[i]) {
            cout << player << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
