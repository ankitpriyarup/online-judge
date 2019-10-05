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

    int ans = 1e9 + 5;
    string t = "bon";
    for (char c : t) {
        ans = min(ans, freq[c - 'a']);
    }

    // 2 -> 1
    // 3 -> 2
    // 4 -> 3

    cout << max(0, ans - 1) << '\n';
    
    return 0;
}
