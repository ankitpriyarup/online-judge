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

    int n, k, q;
    cin >> n >> k >> q;
    vi scores(n, 0);

    int base = q - k;

    while (q-- > 0) {
        int x;
        cin >> x;
        --x;
        ++scores[x];
    }

    // allowed to get at most k - 1 wrong
    // k - 1 + correct = q
    // correct = q - (k - 1)
    for (int i = 0; i < n; ++i) {
        if (scores[i] > base) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
