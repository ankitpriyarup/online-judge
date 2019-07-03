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
        bool valid = 'a' <= s[0] and s[0] <= 'z';
        int words = 1;
        for (char c : s) {
            if ('A' <= c and c <= 'Z') {
                ++words;
            } else if (!('a' <= c and c <= 'z')) {
                valid = false;
            }
        }

        valid &= words <= 7;
        cout << (valid ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
