#include <iostream>
#define MOD 1000000007
using namespace std;

int K, C[1010], binom[1010][1010];

int main() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < 1010; i++) {
        binom[i][0] = 1;
        if (i > 0) {
          binom[i][i] = 1;
        }
    }

    for (int i = 1; i < 1010; i++) {
        for (int j = 1; j < 1010; j++) {
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
        }
    }

    long long ans = 1;
    int total_balls = C[0];
    for (int i = 1; i < K; i++) {
        total_balls += C[i];
        int choose = binom[total_balls - 1][C[i] - 1];
        ans *= choose;
        ans %= MOD;
    }

    cout << ans << '\n';
    return 0;
}
