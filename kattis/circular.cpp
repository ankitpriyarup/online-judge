#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

pii merge(const pii& a, const pii& b) {
    return {a.first + b.first, min(a.second, a.first + b.second)};
}

inline bool valid(const pii& p) {
    return p.first == 0 and p.second >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    vi vals(n);
    vi ids(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        vals[i] = ids[i] = stoi(s[i].substr(1));
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    int m = vals.size();

    vector<vector<pii>> prefs(m);
    vector<vector<pii>> suffs(m);
    for (int i = 0; i < m; ++i) {
        prefs[i].emplace_back(0, 0);
        suffs[i].emplace_back(0, 0);
    }

    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(all(vals), ids[i]) - begin(vals);
        ids[i] = idx;
    }

    for (int i = 0; i < n; ++i) {
        int v = s[i][0] == 's' ? 1 : -1;
        prefs[ids[i]].emplace_back(v, min(0, v));
        suffs[ids[i]].emplace_back(v, min(0, v));
    }

    vi ptrs(m, 1);
    int score = 0;
    for (int i = 0; i < m; ++i) {
        prefs[i].emplace_back(0, 0);
        suffs[i].emplace_back(0, 0);

        int sz = prefs[i].size();
        for (int j = 1; j < sz; ++j) {
            prefs[i][j] = merge(prefs[i][j - 1], prefs[i][j]);
        }
        for (int j = sz - 2; j >= 0; --j) {
            suffs[i][j] = merge(suffs[i][j], suffs[i][j + 1]);
        }

        ptrs[i] = 1;
        score += valid(merge(suffs[i][1], prefs[i][0]));

        /*cout << "i: " << i << '\n';
        for (auto& p : prefs[i]) {
            cout << "(" << p.first << ' ' << p.second << ") ";
        }
        cout << '\n';
        */
    }

    int cut = 1;
    int best_score = score;
    for (int i = 0; i < n; ++i) {
        int k = ids[i];
        score -= valid(merge(suffs[k][ptrs[k]], prefs[k][ptrs[k] - 1]));
        ++ptrs[k];
        score += valid(merge(suffs[k][ptrs[k]], prefs[k][ptrs[k] - 1]));
        if (score > best_score) {
            best_score = score;
            cut = i + 2;
        }
    }

    cout << cut << ' ' << best_score << '\n';

    return 0;
}
