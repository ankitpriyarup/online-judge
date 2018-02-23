#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>
#define x1 asdjghasdljkghkj
#define x2 ajsfhdgkjasdhgjk
#define y1 ajbfhkjxcjkhzxcx
#define y2 uyzxoxhdahfjkaeh

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using plat = tuple<int, int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    int y, x1, x2;
    vector<plat> plats(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &y, &x1, &x2);
        plats[i] = make_tuple(y, x1, x2 - 1);
    }

    int yy, xx1, xx2;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        tie(y, x1, x2) = plats[i];
        int first_leg = y;
        int second_leg = y;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            tie(yy, xx1, xx2) = plats[j];
            if (yy < y and xx1 <= x1 and x1 <= xx2) {
                // printf("Point %d in range [%d, %d]\n", x1, xx1, xx2);
                first_leg = min(first_leg, y - yy);
            }

            if (yy < y and xx1 <= x2 and x2 <= xx2) {
                second_leg = min(second_leg, y - yy);
            }
        }

        ans += first_leg;
        ans += second_leg;

        // printf("Seg (%d, %d, %d) has legs %d and %d\n", y, x1, x2, first_leg, second_leg);
    }

    printf("%lld\n", ans);

    return 0;
}
