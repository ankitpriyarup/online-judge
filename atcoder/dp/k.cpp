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

    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vi win(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        for (int x : a) {
            if (x > i)
                break;
            if (!win[i - x]) {
                win[i] = true;
                break;
            }
        }
    }

    cout << (win[k] ? "First" : "Second") << '\n';

    return 0;
}
