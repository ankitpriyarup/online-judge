#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;
        if (k == 1) {
            cout << (1LL * n * m) << '\n';
        } else if (k == 2) {
            if (n % 2 == 1 and m % 2 == 1) {
                cout << (1LL * n * m) << '\n';
            } else {
                cout << (-1) << '\n';
            }
        } else {
            if (gcd(n, k) == 1 and gcd(m, k) == 1) {
                cout << (1LL * n * m) << '\n';
            } else {
                cout << (-1) << '\n';
            }
        }
    }
    
    return 0;
}
