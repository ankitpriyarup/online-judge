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
    int bad = 0;
    int rem = s.size();
    for (int j = 0; j < 26; ++j) {
        int old_rem = rem;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[j])
                --rem;
        }
        if (rem == 0) break;
        if (rem == old_rem) ++bad;
    }

    cout << (bad < 10 ? "WIN" : "LOSE") << '\n';
    
    return 0;
}
