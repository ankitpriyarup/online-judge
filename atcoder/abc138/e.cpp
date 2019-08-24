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

    string s, t;
    cin >> s >> t;
    int n = s.size();

    vector<vi> jump(n, vi(26, -1));
    jump[n - 1][s[n - 1] - 'a'] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            jump[i][j] = jump[i + 1][j];
        }
        jump[i][s[i] - 'a'] = i;
    }

    int m = t.size();
    int p = 0;
    int k = 0;
    for (int i = 0; i < m; ++i) {
        int c = t[i] - 'a';
        if (jump[p][c] == -1) {
            if (jump[0][c] == -1) {
                cout << "-1\n";
                return 0;
            }

            ++k;
            p = jump[0][c] + 1;
        } else {
            p = jump[p][c] + 1;
        }

        if (p > n - 1) {
            p = 0;
            ++k;
        }
    }

    ll ans = 1LL * n * k + p;

    cout << ans << '\n';
    
    return 0;
}
