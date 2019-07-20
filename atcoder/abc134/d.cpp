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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vi ans(n + 1, 0);
    vi res;
    bool valid = true;
    for (int i = n; i > 0; --i) {
        int tot = 0;
        for (int j = i; j <= n; j += i) {
            tot += ans[j];
        }

        if (tot % 2 != a[i] % 2) {
            ++ans[i];
            res.push_back(i);
        }
    }

    reverse(all(res));
    cout << res.size() << '\n';
    for (auto& x : res) {
        cout << x << ' ';
    }
    
    return 0;
}
