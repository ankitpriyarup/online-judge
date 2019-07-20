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

    int n, d;
    cin >> n >> d;
    int range = 2 * d + 1;
    int ans = (n + range - 1) / range;
    cout << ans << '\n';
    
    return 0;
}
