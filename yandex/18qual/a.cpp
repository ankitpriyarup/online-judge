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

constexpr int MAXN = 1003;
int n;
int a[10];
int b[MAXN][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; ++i)
        scanf("%d", a + i);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int matches = 0;
        for (int j = 0; j < 6; ++j) {
            scanf("%d", &b[i][j]);
            for (int k = 0; k < 10; ++k) {
                if (b[i][j] == a[k]) {
                    ++matches;
                    break;
                }
            }
        }

        if (matches >= 3) {
            printf("Lucky\n");
        } else {
            printf("Unlucky\n");
        }
    }

    return 0;
}
