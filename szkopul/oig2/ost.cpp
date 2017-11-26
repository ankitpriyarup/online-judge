#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

int freq[500];
char buf[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // find all values x such that
    // 10^k | x^a - x
    // Try each case separately
    // 10^k | x^2 - x
    // 10^k | x * (x - 1)
    // We need to get enough 5s and 2s between them
    // all the fives need to be in one or the other,
    // they can't both contribute
    // Only have to check multiples of 5^k up to 10^k

    // Similarly,
    // 10^k | x^3 - x
    // 10^k | x (x^2 - 1)
    // 10^k | x * (x + 1) * (x - 1)
    // So same thing?

    int k, a;
    scanf("%d %d", &k, &a);
    ll base = 1;
    ll cap = 1;
    for (int i = 0; i < k; ++i) {
        base *= 5LL;
        cap *= 10LL;
    }

    vector<ll> ans;
    for (ll x = 0; x <= cap + 5; x += base) {
        if (a == 2) {
            for (int d = -1; d <= 0; ++d) {
                ll val = (x + d) * (x + d + 1) % cap;
                if (val == 0 and x + d + 1 < cap) ans.push_back(x + d + 1);
            }
        } else {
            for (int d = -2; d <= 0; ++d) {
                ll val = (x + d) * (x + d + 1) % cap * (x + d + 2) % cap;
                if (val == 0 and x + d + 1 < cap) ans.push_back(x + d + 1);
            }
        }
    }

    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] >= 0)
            printf("%lld%c", ans[i], " \n"[i + 1 == ans.size()]);
    }

    return 0;
}
