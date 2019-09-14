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

    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    sort(all(a));
    vi c(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] > 0) continue;
        c[i] = ++ans;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] % a[i] == 0) {
                c[j] = c[i];
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
