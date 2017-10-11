#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 15;
int n, p;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    if (a[p] > 300) {
        printf("%d %d\n", 0, 0);
        return 0;
    }


    int time = a[p];
    int penalty = a[p];
    a[p] = 301;
    int ac = 1;

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (time + a[i] > 300) {
            break;
        }

        time += a[i];
        penalty += time;
        ++ac;
    }

    printf("%d %d\n", ac, penalty);

    return 0;
}
