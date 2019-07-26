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

    string s;
    cin >> s;

    int n = s.size();
    string ans(n, '0');
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t(s);
            swap(t[i], t[j]);
            if (t < s and t[0] != '0') {
                ans = max(ans, t);
            }
        }
    }

    if (ans[0] == '0') {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    
    return 0;
}
