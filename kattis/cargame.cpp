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
    vector<string> words(n);
    vector<vector<array<int, 26>>> dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];

        int k = words[i].size();
        dp[i].resize(k + 1);
        dp[i][k].fill(-1);
        for (int j = k - 1; j >= 0; --j) {
            for (int v = 0; v < 26; ++v) {
                dp[i][j][v] = dp[i][j + 1][v];
            }

            dp[i][j][words[i][j] - 'a'] = j;
        }
    }

    while (m-- > 0) {
        string query;
        cin >> query;

        bool found = false;
        for (int i = 0; i < n; ++i) {
            int p = 0;
            for (int j = 0; j < 3; ++j) {
                int np = dp[i][p][query[j] - 'A'];
                if (np == -1) {
                    p = -1;
                    break;
                } else {
                    p = np + 1;
                }
            }

            if (p >= 0) {
                found = true;
                cout << words[i] << '\n';
                break;
            }
        }

        if (!found) {
            cout << "No valid word\n";
        }
    }

    return 0;
}
