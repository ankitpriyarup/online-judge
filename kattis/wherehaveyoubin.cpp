#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const string VOWELS = "AEIOU";

constexpr int MAXN = 202;
int owner[MAXN], a[MAXN];
int freq[5], tot[5];
int dp[MAXN][1 << 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
            owner[i] = -1;
        } else {
            while (s[i] != VOWELS[owner[i]])
                ++owner[i];
            ++freq[owner[i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tot[owner[i]] += a[i];
    }

    int m;
    cin >> m;
    while (m-- > 0) {
        int x;
        cin >> x;
        --x;
        --freq[owner[x]];
        tot[owner[x]] -= a[x];
        owner[x] = -1;
        a[x] = 0;
    }

    string want;
    cin >> want;
    if (want != "X") {
        for (char c : want) {
            int o = 0;
            while (c != VOWELS[o])
                ++o;

            ++freq[o];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = 0;

        for (int mask = 1; mask < (1 << 5); ++mask) {
            dp[i][mask] = min(dp[i][mask], dp[i + 1][mask]);
            for (int j = 0; j < 5; ++j) {
                if ((mask & (1 << j)) == 0) {
                    continue;
                }

                int old = mask ^ (1 << j);
                if (freq[j] == 0) {
                    dp[i][mask] = dp[i][old];
                } else if (i + freq[j] <= n) {
                    int cost = tot[j];
                    for (int k = i; k < i + freq[j]; ++k) {
                        if (owner[k] == j) {
                            cost -= a[k];
                        }
                    }

                    dp[i][mask] = min(dp[i][mask], cost + dp[i + freq[j]][old]);
                }
            }
        }
    }

    cout << dp[0][(1 << 5) - 1] << '\n';

    return 0;
}
