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

ld eval(int val) {
    ld x = 0.0L;
    ld y = 0.0L;
    int theta = 0;

    for (int i = 0; i < n; ++i) {
        int a = argument[i] == -1 ? val : argument[i];
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

    return x * x + y * y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    char buf[30];

    while (T-- > 0) {
        scanf("%d", &n);
        bool is_angle = false;
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", cmd[i], buf);

            // printf("%s %s\n", cmd[i], buf);

            if (buf[0] == '?') {
                argument[i] = -1;
                is_angle = cmd[i][0] == 'l' or cmd[i][0] == 'r';
            } else {
                int x = atoi(buf);
                // printf("%s %d\n", cmd[i], x);
                argument[i] = x;
            }
        }

        if (is_angle) {
            ld min_cost = eval(0);
            int ans = 0;
            for (int theta = 1; theta < 360; ++theta) {
                ld res = eval(theta);
                if (res < min_cost) {
                    min_cost = res;
                    ans = theta;
                }
            }

            printf("%d\n", ans);
        } else {
            int lo = 0;
            int hi = 1e9;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                ld f1 = eval(mid - 1);
                ld f2 = eval(mid);
                // printf("[%d, %d] f(%d) = %.2Lf, f(%d) = %.2Lf\n", lo, hi, mid - 1, f1, mid, f2);
                if (eval(mid - 1) < eval(mid)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            while (eval(lo) > eval(lo + 1)) ++lo;
            printf("%d\n", lo);
        }
    }
    
    return 0;
}
