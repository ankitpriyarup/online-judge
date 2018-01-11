#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 102;
int n, m, k;
int a[MAXN][MAXN];
int score = 0;
int deleted = 0;

void process(int c) {
    int sum = 0;
    for (int r = 0; r < k; ++r) {
        sum += a[r][c];
    }

    int best_sum = 0;
    int best_rem = 0;
    int cur_rem = 0;
    for (int r = 0; r < n; ++r) {
        if (a[r][c] == 1) {
            if (sum > best_sum) {
                best_sum = sum;
                best_rem = cur_rem;
            }

            --sum;
            ++cur_rem;
        }

        if (r + k < n) {
            sum += a[r + k][c];
        }
    }

    score += best_sum;
    deleted += best_rem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; ++i) {
        process(i);
    }

    printf("%d %d\n", score, deleted);
    
    return 0;
}
