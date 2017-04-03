#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;
int n, c, k;
int a[MAXN];

int main() {
    scanf("%d %d %d", &n, &c, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + n);

    int bus_time = 0;
    int cap_left = 0;
    int buses = 0;

    for (int i = 0; i < n; ++i) {
        if (cap_left == 0 or a[i] > bus_time or a[i] + k < bus_time) {
            ++buses;
            cap_left = c - 1;
            bus_time = a[i] + k;
        } else {
            cap_left -= 1;
        }
    }

    printf("%d\n", buses);

    return 0;
}
