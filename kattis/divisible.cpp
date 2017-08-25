#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

constexpr int MAXD = 1e9 + 9;
constexpr int MAXN = 50004;

int d, n;

int main() {
    int T, x;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d %d", &d, &n);
        map<int, int> freq;

        freq[0] = 1;

        int sum = 0;
        long long ans = 0LL;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);

            sum = (sum + x) % d;
            ans += freq[sum];
            ++freq[sum];
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}
