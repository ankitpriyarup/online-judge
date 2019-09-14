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

    ll n, m;
    cin >> n >> m;
    ll k = 0;
    while ((1LL << k) < n)
        ++k;

    cout << ((k + m - 1) / m) << '\n';
    
    return 0;
}
