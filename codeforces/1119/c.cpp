#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    vvi b(n, vi(m));
    vi ar(n, 0), ac(m, 0), br(n, 0), bc(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            ar[i] ^= a[i][j];
            ac[j] ^= a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            br[i] ^= b[i][j];
            bc[j] ^= b[i][j];
        }
    }
    if (ar == br and ac == bc) {
        cout << "Yes\n";
    } else  {
        cout << "No\n";
    }
    
    return 0;
}
