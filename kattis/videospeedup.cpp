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

    int n, p, k;
    cin >> n >> p >> k;

    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }
    a.push_back(k);
    double mult = 1.0;
    double ans = 0.0;
    for (int i = 0; i <= n; ++i) {
        int dur = a[i];
        if (i) dur -= a[i - 1];

        ans += dur * mult;
        mult += p / 100.0;
    }

    cout << fixed << setprecision(12) << ans << '\n';
    
    return 0;
}
