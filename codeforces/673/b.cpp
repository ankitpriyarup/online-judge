#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x, y;
    int l1 = 1;
    int s2 = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        if (x > y) {
            int t = x;
            x = y;
            y = t;
        }

        l1 = max(l1, x);
        s2 = min(s2, y);
    }

    if (l1 >= s2) {
        printf("0\n");
    } else {
        printf("%d\n", s2 - l1);
    }

    return 0;
}
