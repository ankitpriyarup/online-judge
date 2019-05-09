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

    int n;
    string s;
    cin >> n >> s;
    map<pii, int> last;
    last[{0, 0}] = 0;
    pii cur = {0, 0};

    int l = -1;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            --cur.first;
        } else if (s[i] == 'D') {
            ++cur.first;
        } else if (s[i] == 'L') {
            --cur.second;
        } else {
            ++cur.second;
        }

        if (last.find(cur) != end(last)) {
            l = max(l, last[cur]);
        }
        ans = max(ans, i - l);
        last[cur] = i + 1;
    }

    cout << ans << '\n';
    
    return 0;
}
