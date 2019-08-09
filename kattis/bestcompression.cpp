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

    ll n, b;
    cin >> n >> b;
    ll m = (1LL << (b + 1LL)) - 1LL;
    cout << (n <= m ? "yes" : "no") << '\n';
    
    return 0;
}
