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

    int off = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        off += x != i;
    }

    cout << ((off == 0 or off == 2) ? "YES" : "NO") << '\n';
    
    return 0;
}
