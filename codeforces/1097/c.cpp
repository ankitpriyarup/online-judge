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

    int n;
    cin >> n;

    string s;

    map<int, vector<int>> opts;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int min_pref = 0;
        int sum = 0;
        for (int j = 0; j < s.size(); ++j) {
            sum += (s[j] == '(' ? 1 : -1);
            min_pref = min(min_pref, sum);
        }

        // cout << "Found " << sum << " " << min_pref << '\n';
        opts[sum].push_back(min_pref);
    }

    int ans = 0;
    for (auto& e : opts) {
        int sum = e.first;
        if (sum > 0) {
            continue;
        } else if (sum == 0) {
            // everything is 0
            // if first >= 0, lo >= -first
            int zeros = 0;
            for (int x : e.second) {
                if (x == 0) {
                    ++zeros;
                }
            }

            ans += zeros >> 1;
        } else {
            // cout << "Handling sum " << sum << '\n';
            vi lo_prefs = e.second;
            vi hi_prefs = opts[-sum];

            sort(all(lo_prefs));
            sort(all(hi_prefs));

            /*
            for (int x : lo_prefs) {
                cout << x << ' ';
            }
            cout << '\n';
            for (int x : hi_prefs) {
                cout << x << ' ';
            }
            cout << '\n';
            */

            int ptr = 0;
            // hi prefs have sum > 0
            // they must be first
            // they can't be negative
            for (int pref : hi_prefs) {
                if (pref < 0) {
                    continue;
                }

                // otherwise, can pair with any lo pref given that lo_pref >= -sum
                while (ptr < (int)lo_prefs.size() and lo_prefs[ptr] < sum) {
                    ++ptr;
                }

                if (ptr >= (int) lo_prefs.size())
                    break;
                ++ans;
                ++ptr;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
