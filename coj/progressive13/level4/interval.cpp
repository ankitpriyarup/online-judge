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

    int T;
    cin >> T;
    while (T-- > 0) {
        map<int, int> m;
        int n;
        cin >> n;
        while (n-- > 0) {
            int x;
            cin >> x;
            ++m[x];
        }
        m[-1] = 1;
        m[100001] = 1;

        int q;
        cin >> q;
        while (q-- > 0) {
            int p, y;
            cin >> p >> y;
            if (p == 1) {
                int x = prev(m.lower_bound(y))->first;
                int z = m.upper_bound(y)->first;
                cout << x << ' ' << z << '\n';
            } else if (p == 2) {
                ++m[y];
            } else {
                m[y] = max(0, m[y] - 1);
                if (m[y] == 0) {
                    m.erase(y);
                }
            }
        }
    }
    
    return 0;
}
