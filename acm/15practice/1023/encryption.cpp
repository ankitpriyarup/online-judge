#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, Q;

    while (cin >> N >> Q) {
        if (N == 0) {
            break;
        }

        // The input array
        int a[N];
        
        // dp[k] = largest index i such that a[i] = a[j] for some i < j <= k
        int dp[N];

        memset(dp, -1, sizeof(dp));

        // previous[x] = latest index of x in a
        map<int, int> previous;

        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            if (i > 0) {
                dp[i] = dp[i - 1];
            }

            if (previous.find(a[i]) != previous.end()) {
                dp[i] = max(dp[i], previous[a[i]]);
            }
            previous[a[i]] = i;
        }

        int x, y;
        for (int i = 0; i < Q; ++i) {
            cin >> x >> y;
            x--;
            y--;
            if (dp[y] >= x) {
                cout << a[dp[y]] << '\n';
            } else {
                cout << "OK\n";
            }
        }
    }

    return 0;
}
