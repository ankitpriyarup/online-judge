#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    string s;
    cin >> s;

    bool has_ns = false;

    int n = s.size();
    for (int i = 1; i < n; ++i) {
        has_ns |= s[i - 1] == 'N' or s[i] == 'N';
        if (s[i - 1] == 'N' and s[i] == 'N') {
            cout << "0 0\n";
            return;
        }
    }

    if (!has_ns) {
        cout << "0 0\n";
        return;
    }

    bool is_a = s[0] == 'N';
    cout << is_a << ' ' << 1 << '\n';
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
