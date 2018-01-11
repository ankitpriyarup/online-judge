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

constexpr int MAXN = 100005;
char a[MAXN], b[MAXN];
int freq[26];

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        memset(freq, 0, sizeof(freq));
        scanf("%s %s", a, b);
        int n = strlen(a);
        int m = strlen(b);

        for (int i = 0; i < m; ++i) {
            freq[b[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[a[i] - 'a'] > 0) {
                --freq[a[i] - 'a'];
                ++ans;
            } else {
                break;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
