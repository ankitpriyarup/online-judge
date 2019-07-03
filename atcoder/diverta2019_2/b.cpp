#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 55;
int n;
int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<pii, int> freq;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            ++freq[{dx, dy}];
            ++freq[{-dx, -dy}];
        }
    }

    int ans = n;
    for (auto it : freq) {
        ans = min(ans, n - it.second);
    }

    cout << ans << '\n';

    return 0;
}
