#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;

        vi ways(m + 1, 0);
        ways[0] = 1;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            for (int j = 0; j + x <= m; ++j) {
                ways[j + x] += ways[j];
                if (ways[j + x] >= MOD)
                    ways[j + x] -= MOD;
            }
        }

        cout << ways[m] << '\n';
    }
    
    return 0;
}
