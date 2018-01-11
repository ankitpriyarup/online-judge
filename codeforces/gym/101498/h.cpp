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

constexpr int MAXN = 1000006;
int n, s;
char buf[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d %d", &n, &s);
        memset(buf, 0, sizeof(buf));

        int start = 0;
        int end = n - 1;
        while (start < end) {
            for (int i = 9; i >= 0; --i) {
                if (2 * i <= s) {
                    s -= 2 * i;
                    buf[start] = '0' + i;
                    buf[end] = buf[start];
                    break;
                }
            }

            ++start;
            --end;
        }

        if (n % 2 == 1) {
            for (int i = 9; i >= 0; --i) {
                if (i <= s) {
                    s -= i;
                    buf[n / 2] = '0' + i;
                    break;
                }
            }
        }

        if (s > 0 or buf[0] == '0') {
            printf("%d\n", -1);
        } else {
            printf("%s\n", buf);
        }
    }

    return 0;
}
