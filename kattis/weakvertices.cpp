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

constexpr int MAXN = 30;
int n;
int a[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d", &n) == 1) {
        if (n <= 0) break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }

        vector<int> weak;
        for (int i = 0; i < n; ++i) {
            bool triangle = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    if (i == k or j == k) continue;

                    if (a[i][j] and a[i][k] and a[k][j]) {
                        triangle = true;
                    }
                }
            }

            if (!triangle) weak.push_back(i);
        }

        for (int x : weak)
            printf("%d ", x);
        printf("\n");
    }
    
    return 0;
}
