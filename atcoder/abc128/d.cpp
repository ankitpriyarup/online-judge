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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vi> prefs(n + 1), suffs(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            prefs[j].push_back(a[i]);
        }

        for (int j = n - i; j <= n; ++j) {
            suffs[j].push_back(a[i]);
        }
    }

    for (int i = 0; i <= n; ++i) {
        sort(all(prefs[i]));
        sort(all(suffs[i]));
    }

    // left[i][j] best score you can get by taking i from the left and dropping j
    vector<vi> lefts(n + 1, vi(k + 1, 0));
    vector<vi> rights(n + 1, vi(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int x : prefs[i])
            lefts[i][0] += x;

        for (int x : suffs[i])
            rights[i][0] += x;

        for (int j = 1; j <= k; ++j) {
            if (j - 1 < prefs[i].size() and prefs[i][j - 1] < 0) {
                lefts[i][j] = lefts[i][j - 1] - prefs[i][j - 1];
            } else {
                lefts[i][j] = lefts[i][j - 1];
            }

            if (j - 1 < suffs[i].size() and suffs[i][j - 1] < 0) {
                rights[i][j] = rights[i][j - 1] - suffs[i][j - 1];
            } else {
                rights[i][j] = rights[i][j - 1];
            }
        }
    }

    int ans = 0;
    for (int drop = 0; drop <= n; ++drop) {
        int take = min(n, k - drop);
        if (take < drop) break;

        for (int l = 0; l <= take; ++l) {
            int r = take - l;
            for (int dl = 0; dl <= drop; ++dl) {
                int dr = drop - dl;
                ans = max(ans, lefts[l][dl] + rights[r][dr]);
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
