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
        int a,b , c, d;
        cin >> a >> b >> c >> d;
        cout << (abs(a - c) + abs(b - d)) << '\n';
    }
    
    return 0;
}
