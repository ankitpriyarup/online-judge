#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;

int n;
char buf[55];
int freq[(int) 1e6];

int main() {
    int T;
    scanf("%d", &T);

    int x;
    int ans = 0;
    while (T-- > 0) {
        memset(freq, 0, sizeof(freq));
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%s %d", buf, &x);
            freq[x]++;

            if (freq[x] > freq[ans]) {
                ans = x;
            }

            if (freq[x] == freq[ans]) {
                ans = min(x, ans);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
