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

constexpr int MAXN = static_cast<int>(1e6 + 6);
constexpr int MOD = 1000009;

char s[MAXN];
ll fib[MAXN];

bool myisvowel(char c) {
    return c == 'a'
        or c == 'e'
        or c == 'i'
        or c == 'o'
        or c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < MAXN; ++i)
        fib[i] = (0LL + fib[i - 1] + fib[i - 2]) % MOD;

    scanf("%s", s);
    int n = strlen(s);
    ll ans = 1;
    int run = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i] == 'o' and !myisvowel(s[i - 1]) and s[i - 1] == s[i + 1]) {
            ++run;
            ++i;
        } else {
            // printf("%d\n", run);
            ans *= (run + 3) / 2;
            ans %= MOD;
            run = 0;
        }
    }

    // printf("%d\n", run);
    ans *= (run + 3) / 2;
    ans %= MOD;

    printf("%lld\n", ans);

    return 0;
}
