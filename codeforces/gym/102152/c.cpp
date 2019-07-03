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
        int n, m;
        cin >> n >> m;
        int a = (n % 2 == 1 ? -1 : 1) + 1;
        int b = (m % 2 == 1 ? -1 : 1) + 1;
        if (a % 3 == 0 and b % 3 == 0) {
            cout << 12 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    
    return 0;
}
