#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1003;
int n, m, h, w;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h >> w;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    int lo = -1;
    int hi = n * m + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] > mid) {
                    b[i][j] = -1;
                } else if (a[i][j] < mid) {
                    b[i][j] = 1;
                } else {
                    b[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            }
        }

        int max_sum = -n*m;
        for (int i = h; i <= n; ++i) {
            for (int j = w; j <= m; ++j) {
                int sum = b[i][j] - b[i - h][j] - b[i][j - w] + b[i - h][j - w];
                max_sum = max(max_sum, sum);
            }
        }

        // cout << mid << " " << max_sum << '\n';
        if (max_sum >= 0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';
    
    return 0;
}
