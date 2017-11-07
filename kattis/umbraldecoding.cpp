#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXK = 105;
int n, k;
int cx[MAXK], cy[MAXK], b[MAXK];

inline bool overlap(const int& x, const int& y, const int& ind) {
    ll xd = x - cx[ind];
    ll yd = y - cy[ind];

    if (xd * xd > b[ind] or yd * yd > b[ind] or xd * xd + yd * yd > b[ind])
        return false;

    return abs(xd * xd * xd) + abs(yd * yd * yd) <= b[ind];
}

ll solve(const int& left, const int& bot, const int& right, const int& top) {
    // printf("solve(%d, %d, %d, %d)\n", left, bot, right, top);
    ll pts = 1LL * (top - bot + 1) * (right - left + 1);
    // printf("Region contains %lld points\n", pts);
    bool some_overlap = false;
    for (int i = 0; i < k; ++i) {
        // see if there's a total overlap
        if (overlap(left, bot, i) and overlap(left, top, i)
        and overlap(right, bot, i) and overlap(right, top, i)) {
            return pts;
        }

        int near_x = min(max(left, cx[i]), right);
        int near_y = min(max(bot, cy[i]), top);
        some_overlap |= overlap(near_x, near_y, i);
    }

    if (!some_overlap) {
        return 0LL;
    }

    int mid_x = left + ((right - left) >> 1);
    int mid_y = bot + ((top - bot) >> 1);

    return solve(left, bot, mid_x, mid_y)
        + solve(left, mid_y + 1, mid_x, top)
        + solve(mid_x + 1, bot, right, mid_y)
        + solve(mid_x + 1, mid_y + 1, right, top);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", cx + i, cy + i, b + i);
    }

    ll safe = solve(0, 0, n, n);

    printf("%lld\n", 1LL * (n + 1) * (n + 1) - safe);
    
    return 0;
}
