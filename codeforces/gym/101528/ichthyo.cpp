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

constexpr int MAXN = 52;
int n;
int a[MAXN];

int f(int x) {
    return max(1000 - x, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("ichthyo.in", "r", stdin);
    freopen("ichthyo.out", "w", stdout);

    scanf("%d", &n);
    multiset<pii> ms;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ms.insert({f(a[i]), i});
    }

    int time = 0;
    int pos = 0;
    while (true) {
        pii cur = *ms.begin();
        ms.erase(ms.begin());
        // printf("%d %d\n", cur.first, cur.second);
        if (cur.first - time < abs(pos - cur.second)) {
            printf("%d\n", cur.first);
            return 0;
        }

        time = cur.first;
        pos = cur.second;
        ++a[pos];
        ms.insert({time + f(a[pos]), pos});
    }

    return 0;
}
