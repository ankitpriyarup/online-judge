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

    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;

        int n = s.size();
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            valid &= (s[i - 1] + 1 == s[i]) or (s[i - 1] == 'z' and s[i] == 'a');
        }

        cout << (valid ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
