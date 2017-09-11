#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;

const int MAXN = 33;
int n;
char s[MAXN];

int main() {
    scanf("%s", s);

    n = strlen(s);

    long long x = 0;
    long long y = 0;

    ll step = (1 << n);
    step >>= 1;

    for (int i = 0; i < n; ++i) {
        int dir = s[i] - '0';
        if (dir & 0x1) {
            x += step;
        } 

        if (dir & 0x2) {
            y += step;
        }

        step >>= 1;
    }

    printf("%d %lld %lld\n", n, x, y);

    return 0;
}
