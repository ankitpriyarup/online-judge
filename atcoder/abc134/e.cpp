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
    int ans = 0;
    multiset<int> ms;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto it = ms.lower_bound(x);
        if (it == begin(ms)) {
            ++ans;
            ms.insert(x);
        } else {
            it = prev(it);
            ms.erase(it);
            ms.insert(x);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
