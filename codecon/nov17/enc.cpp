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

int main() {
    ll n;
    scanf("%lld", &n);

    ll ans = 0;
    for (ll i = 1; i * i <= n; ++i) {
        for (int j = 1; j <= i and i * i + j * j <= n; ++j) {
            for (int k = 1; k <= j and i * i + j * j + k * k <= n; ++k) {
                if (i * i + j * j + k * k == n){
                    ans += i + j + k;
                }

            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
