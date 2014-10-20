#include <iostream>

using namespace std;
int N, K;
int a[200020];
int dp[200020];
int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }

    for(int i=0; i<K;i++) {
        dp[0] += a[i];
    }
    int best = 0;
    int bestVal = dp[0];

    for(int i=1;i<=N-K;i++) {
        dp[i] = dp[i - 1] - a[i - 1] + a[i + K - 1];
        if (dp[i] < bestVal) {
            bestVal = dp[i];
            best = i;
        }
    }
    cout << (best + 1) << '\n';
    return 0;
}
