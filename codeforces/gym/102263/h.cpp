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

    ll n, k;
    cin >> n >> k;

    ll faces = 2 * n;
    ll rounds = (faces + 2 * k - 1) / (2 * k);

    cout << max(10LL, 5 * rounds) << '\n';

    return 0;
}
