#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

string s;
int dp[10004][2];
int main() {
    cin >> s;
    set<string> ans;
    int n = s.size();

    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;
    dp[n][1] = 1;

    for (int i = n - 2; i > 4; --i) {
        string frag = s.substr(i, 2);
        bool no_repeat = i + 2 == n or (i + 4 <= n and frag != s.substr(i + 2, 2));

        if ((no_repeat and dp[i + 2][0]) or dp[i + 2][1]) {
            ans.insert(frag);
            dp[i][0] = 1;
        }

        if (i < n - 2) {
            frag = s.substr(i, 3);
            no_repeat = i + 3 == n or (i + 6 <= n and frag != s.substr(i + 3, 3));
            if ((no_repeat and dp[i + 3][1]) or dp[i + 3][0]) {
                ans.insert(frag);
                dp[i][1] = 1;
            }
        }
    }

    cout << ans.size() << '\n';
    for (string frag : ans) {
        cout << frag << '\n';
    }

    return 0;
}
