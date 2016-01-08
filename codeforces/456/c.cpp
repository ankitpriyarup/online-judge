#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int N;
long long dp[100001];

int main() {
    cin >> N;
    int tmp;
    map<int, int> freq;

    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        freq[tmp]++;
    }

    dp[0] = 0LL;
    dp[1] = freq[1];

    for (int i = 2; i <= 100000; ++i) {
        dp[i] = max(1LL * i * freq[i] + dp[i - 2], dp[i - 1]);
    }

    cout << dp[100000] << '\n';

    return 0;
}
