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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);

    vector<int> evens, odds;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            evens.push_back(x);
        } else {
            odds.push_back(x);
        }
    }

    sort(begin(evens), end(evens));
    sort(begin(odds), end(odds));

    ll ans = odds.back();
    odds.pop_back();
    while (odds.size() >= 2 and odds.back() + odds[odds.size() - 2] > 0) {
        ans += odds.back();
        odds.pop_back();
        ans += odds.back();
        odds.pop_back();
    }

    while (!evens.empty() and evens.back() > 0) {
        ans += evens.back();
        evens.pop_back();
    }

    printf("%lld\n", ans);

    return 0;
}
