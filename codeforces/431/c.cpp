#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std;

int n, k, d;
long long ways[101];
long long waysd[101];

int main() {
    cin >> n >> k >> d;

    memset(ways, 0, sizeof(ways));
    memset(waysd, 0, sizeof(waysd));

    ways[0] = waysd[0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= k and i + j <= n; ++j) {
            ways[i + j] += ways[i];
            ways[i + j] %= MOD;
            if (j < d) {
                waysd[i + j] += waysd[i];
                waysd[i + j] %= MOD;
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i)
        cout << ways[i] << ' ';
    cout << '\n';
    for (int i = 0; i <= n; ++i)
        cout << waysd[i] << ' ';
    cout << '\n';
    */

    long long ans = (ways[n] - waysd[n] + MOD) % MOD;

    cout << ans << '\n';
    return 0;
}
