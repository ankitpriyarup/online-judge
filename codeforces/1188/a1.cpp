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
    vi deg(n, 0);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        ++deg[u]; ++deg[v];
    }

    int valid = true;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2) {
            valid= false;
            break;
        }
    }

    cout << (valid ? "YES" : "NO") << '\n';

    return 0;
}
