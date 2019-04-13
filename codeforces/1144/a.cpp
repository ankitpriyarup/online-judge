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
        vi freq(26, 0);
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++freq[s[i] - 'a'];
        }
        int l = 0;
        int r = 25;
        while (l < 26 and freq[l] == 0) ++l;
        while (r > 0 and freq[r] == 0) --r;
        if (l > r) continue;
        int occ = r - l + 1;
        bool valid = occ == n;
        for (int i = l; i <= r; ++i) {
            valid &= freq[i] == 1;
        }

        cout << (valid ? "Yes" : "No") << '\n';
    }
    
    return 0;
}
