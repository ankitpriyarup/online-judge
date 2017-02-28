#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n;
int t[MAXN];
int paid[MAXN];

int solve(int i, int dur, int cost) {
    if (t[i] - t[0] < dur) {
        return cost;
    } else if (t[i] - t[i - 1] >= dur) {
        return paid[i];
    }

    int lo = 0;
    int hi = i - 1;

    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (t[i] - t[mid] < dur) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return paid[hi - 1] + cost;
}

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    memset(paid, 0, sizeof(paid));
    paid[0] = 20;
    for (int i = 1; i < n; ++i) {
        paid[i] = paid[i - 1] + 20;
        // try buying a 90 min pass for 50$
        paid[i] = min(paid[i], solve(i, 90, 50));

        // try buying a 1440 min pass for 120$
        paid[i] = min(paid[i], solve(i, 1440, 120));
    }

    int cum_sum = 0;
    for (int i = 0; i < n; ++i) {
        printf("%d\n", paid[i] - cum_sum);
        cum_sum = paid[i];
    }

    return 0;
}
