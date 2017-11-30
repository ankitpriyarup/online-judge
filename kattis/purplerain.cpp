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

constexpr int MAXN = 1e5 + 5;
int n;
char s[MAXN];
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i - 1] == 'R' ? 1 : -1);
        // printf("%d ", p[i]);
    }
    // printf("\n");

    int max_pref = 0;
    int min_pref = 0;
    pii best = {0, 1};
    int score = 1;

    for (int i = 1; i <= n; ++i) {
        // printf("Options from %d are %d and %d\n", i, p[i] - p[max_pref], p[i] - p[min_pref]);
        if (abs(p[i] - p[max_pref]) > score) {
            score = abs(p[i] - p[max_pref]);
            best = {max_pref, i};
        }

        if (abs(p[i] - p[min_pref]) > score) {
            score = abs(p[i] - p[min_pref]);
            best = {min_pref, i};
        }

        if (p[i] > p[max_pref])
            max_pref = i;

        if (p[i] < p[min_pref])
            min_pref = i;
    }

    printf("%d %d\n", best.first + 1, best.second);
    
    return 0;
}
