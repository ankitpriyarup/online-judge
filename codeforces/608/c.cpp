#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 100005;
int n;
vector<pair<int, int> > beacons;

// dp[i] = number of beacons destroyed if i is the last beacon
int dp[MAXN];

int main() {
    scanf("%d", &n);

    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        beacons.push_back(make_pair(a, b));
    }

    sort(beacons.begin(), beacons.end());
    dp[0] = 0;
    
    for (int i = 1; i < n; ++i) {
        int pos = beacons[i].first;
        int power = beacons[i].second;
        if (power >= (pos - beacons[0].first)) {
            dp[i] = i;
        } else if (power < (pos - beacons[i - 1].first)) {
            dp[i] = dp[i - 1];
        } else {
            int lo = 0;
            int hi = i - 1;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (power >= pos - beacons[mid].first) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            // printf("dp[%d] = %d\n", i, i - hi);
            dp[i] = i - hi + dp[lo];
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        printf("%d ", dp[i]);
    }
    printf("\n");
    */

    int ans = 2 * n;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, n - i - 1 + dp[i]);
        // printf("%d ", n - i - 1 + dp[i]);
    }
    /*
    printf("\n");
    */
    printf("%d\n", ans);

    return 0;
}
