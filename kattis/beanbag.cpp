#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXB = 21;
const int MAXT = 102;

int b;
int needed[MAXB];

int t;
vector<int> farms[MAXT];

int main() {
    scanf("%d", &b);
    for (int i = 0; i < b; ++i) {
        scanf("%d", needed + i);
    }

    scanf("%d", &t);
    int amt, x;
    for (int i = 0; i < t; ++i) {
        scanf("%d", &amt);
        for (int j = 0; j < amt; ++j) {
            scanf("%d", &x);
            --x;
            farms[i].push_back(x);
        }
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << b); ++mask) {
        bool possible = true;

        for (int i = 0; i < t; ++i) {
            bool satisfied = false;
            for (int j = 0; j < farms[i].size(); ++j) {
                if (mask & (1 << farms[i][j])) {
                    // printf("Farmer %d satisfies %d\n", i, farms[i][j]);
                    satisfied = true;
                    break;
                }
            }

            if (!satisfied) {
                possible = false;
                break;
            }
        }

        if (possible) {
            int cost = 0;
            for (int i = 0; i < b; ++i) {
                if ((mask & (1 << i)) == 0) {
                    // printf("Using %d\n", i);
                    cost += needed[i];
                }
            }

            // printf("%x %d\n", mask, cost);
            ans = max(ans, cost);
        }
    }

    printf("%d\n", ans);

    return 0;
}
