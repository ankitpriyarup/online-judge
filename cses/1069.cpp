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

    int ans = 0;
    char last = 'B';
    int cur = 0;
    for (char c : s) {
        if (c == last) {
            ++cur;
        } else {
            last = c;
            cur = 1;
        }

        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
