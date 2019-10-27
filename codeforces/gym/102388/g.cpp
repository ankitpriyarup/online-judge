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
        int n, a, b;
        cin >> n >> a >> b;
        if (a >= n) {
            cout << 1 << '\n';
            continue;
        } else if (b >= a) {
            cout << "-1\n";
            continue;
        }

        // find smallest d where
        // d * a - (d - 1) * b >= n
        // da - db + b >= n
        // da - db >= n - b
        // d >= (n - b) / (a - b)
        int d = (n - b + a - b - 1) / (a - b);
        cout << d << '\n';
    }
    
    return 0;
}
