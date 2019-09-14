#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string goal(s);
    sort(all(goal));

    string res(n, '1');
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == goal[p]) {
            ++p;
        } else {
            res[i] = '2';
        }
    }

    string tmp;
    for (int k = 1; k <= 2; ++k) {
        for (int i = 0; i < n; ++i) {
            if (res[i] == '0' + k) {
                tmp.push_back(s[i]);
            }
        }
    }

    if (goal == tmp) {
        cout << res << '\n';
    } else {
        cout << "-\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
