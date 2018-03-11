#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1003;
constexpr ld EPS = 1e-7;
int n;
char cmd[MAXN][10];
int argument[MAXN];

ld eval() {
    ld x = 0.0L;
    ld y = 0.0L;
    int theta = 0;

    for (int i = 0; i < n; ++i) {
        int a = argument[i];
        // printf("%s %d\n", cmd[i], a);
        // fd lt rt bk
        // t/360 = x/2pi
        if (cmd[i][0] == 'f') {
            x += a * cos(M_PI * theta / 180.0L);
            y += a * sin(M_PI * theta / 180.0L);
        } else if (cmd[i][0] == 'b') {
            // move back
            x -= a * cos(M_PI * theta / 180.0L);
            y -= a * sin(M_PI * theta / 180.0L);
        } else if (cmd[i][0] == 'l') {
            // turn left
            theta += a;
            theta %= 360;
        } else {
            // turn right
            theta += 360 - a;
            theta %= 360;
        }

        // printf("%.2Lf %.2Lf %d\n", x, y, theta);
    }

    return sqrt(x * x + y * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    char buf[30];

    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", cmd[i], buf);

            int x = atoi(buf);
            argument[i] = x;
        }

        printf("%lld\n", static_cast<ll>(eval() + 0.5));
    }
    
    return 0;
}
