#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    string s;
    int ans[26][26];
    memset(ans, 0, sizeof(ans));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        int l = s.size();
        bool two = true;
        for (int i = 0; i < l; ++i) {
            if (s[i] != s[0] && s[i] != s[l - 1]) {
                two = false;
                break;
            }
        }

        if (two) {
            if (s[0] == s[l - 1]) {
                for (int j = 0; j < 26; ++j) {
                    ans[s[0] - 'a'][j] += l;
                    ans[j][s[0] - 'a'] += l;
                }
                ans[s[0] - 'a'][s[0] - 'a'] -= l;
            } else {
                ans[s[0] - 'a'][s[l - 1] - 'a'] += l;
                ans[s[l - 1] - 'a'][s[0] - 'a'] += l;
            }
        }
    }

    int m = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
//            cout << ans[i][j] << ' ';
            m = max(m, ans[i][j]);
        }
//        cout << '\n';
    }

    cout << m << '\n';
}
