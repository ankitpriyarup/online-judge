#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

bool in_range(int x1, int y1, int x2, int y2, int d) {
    int xd = x1 - x2;
    int yd = y1 - y2;
    return (1LL * d * d) >= (1LL * xd * xd) + (1LL * yd * yd);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, d;
    scanf("%d %d", &n, &d);

    int combo = 0;
    int best_combo = 0;

    int x, y;
    int px, py;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);

        if (combo == 0 or in_range(px, py, x, y, d)) {
            ++combo;
        } else {
            combo = 0;
        }

        best_combo = max(combo, best_combo);
        px = x;
        py = y;
    }

    printf("%d\n", best_combo);
    return 0;
}
