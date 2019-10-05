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
    vector<pii> events;
    while (n-- > 0) {
        int a, b;
        cin >> a >> b;
        events.emplace_back(a, 1);
        events.emplace_back(b, -1);
    }

    sort(all(events));
    int ans = 0;
    int cur = 0;
    for (auto& evt : events) {
        cur += evt.second;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
    
    return 0;
}
