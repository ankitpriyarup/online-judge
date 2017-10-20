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

int solve(int n) {
    ll div_sum = 1LL;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            div_sum += i;
            if (i * i != n)
                div_sum += (n / i);
        }
    }

    // printf("%d %lld\n", n, div_sum);

    if (div_sum == n) {
        return 0;
    } else if (abs(div_sum - n) <= 2) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (scanf("%d", &n) == 1) {
        int res = solve(n);
        if (res == 0) {
            printf("%d perfect\n", n);
        } else if (res == 1) {
            printf("%d almost perfect\n", n);
        } else {
            printf("%d not perfect\n", n);
        }
    }
    
    return 0;
}
