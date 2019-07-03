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

    string s;
    cin >> s;
    vi freq(26, 0);
    for (char c : s) {
        ++freq[c - 'a'];
    }

    for (int i = 0; i < 25; ++i) {
        freq[i + 1] += (freq[i] >> 1);
        freq[i] &= 1;
    }

    string res;
    for (int i = 25; i >= 0; --i) {
        for (int j = 0; j < freq[i]; ++j) {
            res.push_back('a' + i);
        }
    }

    cout << res << '\n';
    
    return 0;
}
