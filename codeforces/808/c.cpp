#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <complex>

using namespace std;

const int MAXN = 102;
int n, w;
pair<int, int> a[MAXN];
int filled[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d %d", &n, &w);

    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i] = make_pair(x, i);
    }

    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        filled[i] = (a[i].first + 1) / 2;
        w -= filled[i];
    }

    if (w < 0) {
        printf("%d\n", -1);
        return 0;
    }

    for (int i = n - 1; w > 0 and i >= 0; --i) {
        int take = min(w, a[i].first - filled[i]);
        w -= take;
        filled[i] += take;
    }

    if (w > 0) {
        printf("%d\n", -1);
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int targ = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j].second == i) {
                targ = j;
                break;
            }
        }
        printf("%d%c", filled[targ], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
