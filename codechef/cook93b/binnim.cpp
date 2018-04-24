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
#include <numeric>
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

constexpr int MAXN = 55;
int n;
char start[10];
char stacks[MAXN][MAXN];

// Dee picks 0 stacks, Dum picks 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %s", &n, start);
        int zero = 0;
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            scanf(" %s", stacks[i]);
            int m = strlen(stacks[i]);
            if (stacks[i][0] == '0') {
                ++zero;
                for (int j = 1; j < m; ++j) {
                    if (stacks[i][j] == '0')
                        ++zero;
                }
            } else {
                ++ones;
                for (int j = 1; j < m; ++j) {
                    if (stacks[i][j] == '1') {
                        ++ones;
                    }
                }
            }
        }

        if (zero < ones or (zero == ones and start[1] == 'e')) {
            printf("Dum\n");
        } else {
            printf("Dee\n");
        }
    }

    return 0;
}
