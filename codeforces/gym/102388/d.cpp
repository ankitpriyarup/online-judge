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
    reverse(all(s));

    string t;
    for (char c : s) {
        // rot13
        if ('A' <= c and c <= 'Z') {
            c = (c - 'A' + 13) % 26 + 'a';
        } else {
            c = (c - 'a' + 13) % 26 + 'A';
        }

        t.push_back(c);
    }

    cout << t << '\n';
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
