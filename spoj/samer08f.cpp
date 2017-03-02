#include <iostream>

using namespace std;

int main() {
    int dp[101];
    dp[1] = 1;
    for(int i = 2; i <= 100; i++) {
        dp[i] = 1;
        for(int j = i - 1, sq = 2; j > 0; j--, sq++) {
            dp[i] += sq * sq;
        }
    }
    int N = 1;
    cin >> N;
    while (N != 0) {
        cout << dp[N] << endl;
        cin >> N;
    }
}
