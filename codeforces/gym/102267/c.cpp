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

    int s, x;
    cin >> s >> x;
    int ans = 0;
    while (s > 0) {
        ++ans;

        s /= x;
    }

    cout << ans << '\n';
    
    return 0;
}
