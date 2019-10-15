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

    constexpr int MOD = 1e9 + 7;

    int n, x;
    cin >> n >> x;
    vi coins(n);
    for (auto& coin : coins) {
        cin >> coin;
    }

    vi ways(x + 1, 0);
    ways[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                ways[i] += ways[i - coin];
                if (ways[i] >= MOD)
                    ways[i] -= MOD;
            }
        }
    }

    cout << ways[x] << '\n';
    return 0;
}
