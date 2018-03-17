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

int n;
int a[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", tc++);
        int y;
        while (q-- > 0) {
            scanf("%d", &y);
            int best = 1e9 + 7;
            int ans = -1;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int x = a[i] + a[j];
                    int dist = abs(x - y);
                    if (dist < best) {
                        best = dist;
                        ans = x;
                    }
                }
            }

            printf("Closest sum to %d is %d.\n", y, ans);
        }
    }
    
    return 0;
}
