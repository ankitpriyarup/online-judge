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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    vector<int> xs(2 * T);
    for (int i = 0; i < 2 * T; i += 2) {
        scanf(" %d", &xs[i]);
    }

    if (T == 1) {
        printf("%d\n", xs[0]);
        return 0;
    }

    constexpr int MOD = 10001;
    for (int a = 0; a < MOD; ++a) {
        for (int b = 0; b < MOD; ++b) {
            bool works = true;
            for (int i = 0; i < 2 * T; i += 2) {
                int x1 = (a * xs[i] + b) % MOD;
                xs[i + 1] = x1;

                int x2 = (a * x1 + b) % MOD;
                if (i + 2 < 2 * T and x2 != xs[i + 2]) {
                    works = false;
                    break;
                }
            }

            if (works) {
                // printf("A: %d, B: %d\n", a, b);
                for (int i = 1; i < 2 * T; i += 2) {
                    printf("%d\n", xs[i]);
                }
                return 0;
            }
        }
    }

    
    return 0;
}
