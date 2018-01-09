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

int my_pow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp)
            res *= cur;

        cur *= cur;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (scanf("%d", &n) == 1) {
        int m = n;
        int ret = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int occ = 0;
                while (n % i == 0) {
                    ++occ;
                    n /= i;
                }

                ret *= my_pow(occ, i);
            }
        }

        printf("%d %d\n", m, ret);
    }
    
    return 0;
}
