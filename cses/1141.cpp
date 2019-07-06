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
    cin >> n;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    int l = 0;
    map<int, int> last;
    int ans = 0;
    for (int r = 0; r < n; ++r) {
        int x = a[r];
        if (last.count(x)) {
            l = max(last[x] + 1, l);
        }

        ans = max(ans, r - l + 1);
        last[x] = r;
    }

    cout << ans << '\n';

    return 0;
}
