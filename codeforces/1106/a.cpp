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
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    int ans = 0;
    vi dx = {1, 1, -1, -1};
    vi dy = {1, -1, 1, -1};
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            if (g[i][j] != 'X')
                continue;

            int hit = 1;
            for (int d = 0; d < 4; ++d) {
                hit += g[i + dx[d]][j + dy[d]] == 'X';
            }

            ans += (hit == 5);
        }
    }

    cout << ans << '\n';
    
    return 0;
}
