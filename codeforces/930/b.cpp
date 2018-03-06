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

constexpr int MAXN = 5003;
int n;
char s[MAXN];
int occ1[30];
int occ2[30][MAXN][30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; ++i) {
        int a = s[i] - 'a';
        ++occ1[a];
        for (int gap = 1; gap < n; ++gap) {
            int j = (i + gap) % n;
            int b = s[j] - 'a';

            ++occ2[a][gap][b];
        }
    }

    ld ans = 0.0;
    for (int i = 0; i < 26; ++i) {
        if (!occ1[i]) continue;

        ld prob = static_cast<ld>(occ1[i]) / n;
        ld best_choice = 0.0L;
        for (int j = 1; j < n; ++j) {
            int den = 0;
            int num = 0;
            for (int k = 0; k < 26; ++k) {
                if (occ2[i][j][k] > 0) {
                    // printf("Starting at %c gap %d has %d occs of %c\n", i + 'a', j, occ2[i][j][k], k + 'a');
                }

                den += occ2[i][j][k];
                if (occ2[i][j][k] == 1)
                    ++num;
            }
            ld cur_choice = static_cast<ld>(num) / den;
            // printf("When starting at %c, choosing gap %d gives %.2Lf chance of success\n", i + 'a', j, cur_choice);
            best_choice = max(best_choice, cur_choice);
        }

        ans += prob * best_choice;
    }

    printf("%.17Lf\n", ans);

    return 0;
}
