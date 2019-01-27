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
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '1') continue;

            for (int h = 1; i + h <= n; ++h) {
                for (int w = 1; j + w <= m; ++w) {
                    if (2 * (w + h) < ans) continue;
                    bool works = true;
                    for (int x = i; works and x < i + h; ++x) {
                        for (int y = j; works and y < j + w; ++y) {
                            if (g[x][y] == '1') {
                                works = false;
                                break;
                            }
                        }
                    }

                    if (works) {
                        ans = max(ans, 2 * (w + h));
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
