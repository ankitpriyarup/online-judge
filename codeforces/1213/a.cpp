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
    vi a(2, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x % 2]++;
    }

    cout << min(a[0], a[1]) << '\n';
    
    return 0;
}
