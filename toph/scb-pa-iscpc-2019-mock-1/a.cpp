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

    int n, m;
    cin >> n >> m;
    vi a(n);
    bool valid = true;
    for (auto& x : a) {
        cin >> x;
        valid &= x >= m;
    }

    valid &= n * m == 60;

    cout << (valid ? "YES" : "NO") << '\n';
    
    return 0;
}
