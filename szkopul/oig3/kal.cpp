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

constexpr int MAXN = 1000006;
int n[2];
int a[2][MAXN];
ll pa[2][MAXN];

pair<int, int> get(int k, int raw_day) {
    int ind = lower_bound(pa[k], pa[k] + n[k], raw_day) - pa[k];
    while (ind > 0 and pa[k][ind] > raw_day)
        --ind;

    return {raw_day - pa[k][ind] + 1, ind + 1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n[0], &n[1]);
    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i <= n[k]; ++i) {
            scanf("%d", &a[k][i]);
            pa[k][i] = pa[k][i - 1] + a[k][i];
        }
    }

    int q;
    scanf("%d", &q);
    int day, month;
    while (q-- > 0) {
        char c;
        scanf("%d %d %c\n", &day, &month, &c);
        c -= 'A';
        --month;
        --day;
        int raw_day = pa[c][month] + day;
        pii res = get(1 - c, raw_day);
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}
