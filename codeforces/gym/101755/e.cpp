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

    int l = 0;
    while (l < n and s[l] == t[l])
        ++l;

    int r = n - 1;
    while (r >= 0 and s[r] == t[r])
        --r;

    if (l > r) {
        cout << "YES\n";
        return 0;
    }

    int m = r - l + 1;
    bool valid = true;
    for (int i = 0; i < m; ++i) {
        valid &= s[l + i] == t[r - i];
    }

    cout << (valid ? "YES" : "NO") << '\n';
    
    return 0;
}
