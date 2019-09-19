#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool eq(const vi& m, char s, char t) {
    if (s == t) return true;
    if (m[s - 'a'] == t - 'a')
        return true;
    if (m[t - 'a'] == s - 'a')
        return true;

    return false;
}

void solve() {
    int p;
    cin >> p;
    vi m(26, -1);
    for (int i = 0; i < p; ++i) {
        char s, t;
        cin >> s >> t;
        m[s - 'a'] = t - 'a';
        m[t - 'a'] = s - 'a';
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        string s;
        cin >> s;
        int p0 = 0;
        int p1 = s.size() - 1;
        bool valid = true;
        while (p0 < p1) {
            if (eq(m, s[p0], s[p1])) {
                ++p0;
                --p1;
            } else {
                valid = false;
                break;
            }
        }

        cout << s << " " << (valid ? "YES" : "NO") << "\n";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cout << "Test case #" << tc++ << ":\n";
        solve();
    }
    
    return 0;
}
