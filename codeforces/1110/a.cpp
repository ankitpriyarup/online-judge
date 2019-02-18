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

    int b, k;
    cin >> b >> k;
    vi a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int v = 0;
    for (int i = 0; i < k; ++i) {
        v = 1LL * b * v % 2;
        v += a[i];
        v %= 2;
    }

    cout << (v % 2 == 0 ? "even" : "odd") << '\n';
    
    return 0;
}
