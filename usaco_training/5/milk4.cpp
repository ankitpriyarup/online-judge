/*
USER: rednano1
PROG: milk4
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <bitset>

using namespace std;

const int MAXQ = 20002;
const int MAXP = 104;
int q, p;
int a[MAXP];

struct state {
    bitset<MAXP> bs;
    int popcount;

    bool operator<(const state& other) const {
        if (popcount == other.popcount) {
            for (int i = 0; i < MAXP; ++i) {
                if (!bs[i] and other.bs[i]) {
                    return false;
                } else if (bs[i] and !other.bs[i]) {
                    return true;
                }
            }

            return false;
        } else {
            return popcount < other.popcount;
        }
    }

    state with(const int& j) const {
        if (bs[j]) {
            return *this;
        }

        bitset<MAXP> new_bs = bs;
        new_bs.set(j);
        int new_popcount = popcount + 1;

        return {new_bs, new_popcount};
    }
};

state dp[MAXQ];
bool hit[MAXQ];

int main() {
    freopen("milk4.in", "r", stdin);
    freopen("milk4.out", "w", stdout);

    scanf("%d %d", &q, &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + p);

    memset(hit, false, sizeof(hit));

    dp[0] = {bitset<MAXP>(0LL), 0};
    hit[0] = true;
    for (int i = 0; i < q; ++i) {
        if (!hit[i]) continue;

        for (int j = 0; j < p; ++j) {
            state new_state = dp[i].with(j);

            for (int new_val = i + a[j]; new_val < MAXQ; new_val += a[j]) {
                if (new_val < MAXQ and (!hit[new_val] or new_state < dp[new_val])) {
                    hit[new_val] = true;
                    dp[new_val] = new_state;
                }
            }
        }
    }

    printf("%d", dp[q].popcount);
    for (int i = 0; i < p; ++i) {
        if (dp[q].bs[i]) {
            printf(" %d", a[i]);
        }
    }
    printf("\n");

    return 0;
}
