#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 100005;

int n;
int a[MAXN];

map<vector<int>, int> history;
vector<vector<int> > hist_inv;

int main() {
    ios_base::sync_with_stdio(false);
    int k, x;
    scanf("%d %d %d", &n, &k, &x);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    vector<int> cur(a, a + n);
    sort(cur.begin(), cur.end());

    int cyc_start = -1;
    int cyc_end = -1;
    for (int i = 0; i < k; ++i) {
        if (history.find(cur) != history.end()) {
            cyc_start = history[cur];
            cyc_end = i;
            break;
        }

        history[cur] = i;
        hist_inv.push_back(cur);

        for (int j = 0; j < n; j += 2) {
            cur[j] ^= x;
        }
        sort(cur.begin(), cur.end());
    }

    if (cyc_start == -1) {
        printf("%d %d\n", cur[n - 1], cur[0]);
    } else {
        int ind = cyc_start + ((k - cyc_start) % (cyc_end - cyc_start));
        printf("%d %d\n", hist_inv[ind][n - 1], hist_inv[ind][0]);
    }

    return 0;
}
