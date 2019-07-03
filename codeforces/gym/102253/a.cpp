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

    int m;
    int tc = 1;
    double d = log(10.0) / log(2.0);
    while (cin >> m) {
        int ans = m / d;
        cout << "Case #" << tc++ << ": " << ans << '\n';
    }
    
    return 0;
}
