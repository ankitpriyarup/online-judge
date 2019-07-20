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
    vi p(n), s(n);
    p[0] = a[0];
    s[n - 1] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        p[i] = max(a[i], p[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i){
        s[i] = max(a[i], s[i + 1]);
    }

    vi ans(n);
    ans[0] = s[1];
    ans[n - 1] = p[n - 2];
    for (int i = 1; i + 1 < n; ++i) {
        ans[i] = max(p[i - 1], s[i + 1]);
    }

    for (auto& x : ans) {
        cout << x << '\n';
    }
    
    return 0;
}
