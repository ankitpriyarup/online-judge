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

    
    vi f(26, 0);
    for (int k = 0; k < 3; ++k) {
        string s;
        cin >> s;
        int dir = k == 2 ? -1 : 1;
        for (char c : s) {
            f[c - 'A'] += dir;
        }
    }

    bool valid = true;
    for (int i = 0; i < 26; ++i) 
        valid &= f[i] == 0;

    cout << (valid ? "YES" : "NO") << '\n';
    return 0;
}
