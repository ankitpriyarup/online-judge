#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int modpow(int b, int e) {
    if (!e) return 1;
    int x = modpow(1LL * b * b % MOD, e / 2);
    if (e % 2 == 1) return 1LL * b * x % MOD;
    else return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, n;
    cin >> x >> n;
    cout << modpow(x, n);
    
    return 0;
}
