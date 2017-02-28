#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

char resp[10];

int bin_search(int x, int y) {
    int lo = 0;
    int hi = 1001;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (x == -1)
            printf("? %d %d\n", mid, y);
        else
            printf("? %d %d\n", x, mid);

        fflush(stdout);

        scanf("%s", resp);
        if (resp[0] == 'Y') {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);

    // find the base of the square
    int square_size = 2 * bin_search(-1, 0);

    // find the height of the triangle
    int tri_height = bin_search(0, -1);
    tri_height -= square_size;

    // find the width of the triangle
    int tri_width = 2 * bin_search(-1, square_size);

    long long area = 1LL * square_size * square_size + 1LL * tri_height * tri_width / 2LL;

    printf("! %lld\n", area);
    return 0;
}
