#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 2 or !is_prime(n - 2)) {
        cout << -1 << '\n';
    } else {
        cout << "2 " << (n - 2) << '\n';
    }
    
    return 0;
}
