#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int t;

    scanf("%d", &t);

    while (t-- > 0)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        long long weights[n];
        long long values[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> weights[i];
            cin >> values[i];
        }

        long long dp[n + 1][k + 1];
       
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                dp[i][j] = 0;

        for (int i = 0; i <= k; ++i)
        {
            dp[0][i] = 0;
        }

        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - weights[i - 1] >= 0)
                    dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
        }

        printf("%lld\n", dp[n][k]);
    }
}
