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
        int n;
        cin >> n;

        vi a(n);
        int mi = 1e9 + 7;
        int ma = -mi;
        for (auto& x : a) {
            cin >> x;
            mi = min(mi, x);
            ma = max(ma, x);
        }

        cout << (mi + ma) << '\n';
    }
    
    return 0;
}
