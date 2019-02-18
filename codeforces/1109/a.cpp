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

    vi a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    ll ans = 0LL;
    map<int, int> odd, even;
    even[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            ans += odd[a[i]];
            ++odd[a[i]];
        } else {
            ans += even[a[i]];
            ++even[a[i]];
        }
    }

    cout << ans << '\n';
    
    return 0;
}
