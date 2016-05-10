#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int a[100005];
int dp[100005];

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }

        dp[0] = 3;
        for (int i = 1; i < N; ++i) {
            dp[i] = dp[i - 1] + 3;
            
            // take the last two elements
            if (a[i] - a[i - 1] <= 30 and a[i] > a[i - 1]) {
                dp[i] = min(dp[i], dp[i - 2] + 2);
            }

            // take the last 3 elements
            if (i >= 2) {
                int x = a[i - 2];
                int y = a[i - 1];
                int z = a[i];

                if (x < y and y < z and ((y - x <= 20 and z - y <= 10) or (y - x <= 10 and z - y <= 20))) {
                    dp[i] = min(dp[i], dp[i - 3] + 1);
                }
            }

            // take the last 4 elements
            if (i >= 3) {
                int w = a[i - 3];
                int x = a[i - 2];
                int y = a[i - 1];
                int z = a[i];
                if (w < x and x < y and y < z and x - w <= 10 and y - x <= 10 and z - y <= 10) {
                    dp[i] = min(dp[i], dp[i - 4]);
                }
            }
        }

        /*
        for (int i = 0; i < N; ++i) {
            cout << dp[i] << " ";
        }
        */
        cout << "Case #" << case_num << ": " << dp[N - 1] << '\n';
    }
    return 0;
}
