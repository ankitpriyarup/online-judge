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

    int n, x;
    cin >> n >> x;
    vi a(n);
    for (auto& v : a) {
        cin >> v;
    }
    sort(all(a));
    int ans = 0;
    for (int y : a) {
        if (y + 1 <= x) {
            ++ans;
            x -= y + 1;
        } else {
            break;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
