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

    int ans = 0;
    vector<string> s(7);
    for (int i = 0; i < 7; ++i) {
        cin >> s[i];
        if (s[i] == "J" and (i == 0 or s[i] != s[i - 1]))
            ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}
