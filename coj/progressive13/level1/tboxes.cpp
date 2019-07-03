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
    int x;
    cin >> x;
    cout << (x << 1) << '\n';

    int lo = x;
    int hi = x;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        lo = min(lo, x);
        hi = max(hi, x);

        cout << (lo + hi) << '\n';
    }

    return 0;
}
