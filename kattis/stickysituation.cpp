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

constexpr int MAXN = 22002;
int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", a + i);
    }
    sort(a, a + n);
    bool poss = false;
    for (int i = 1; !poss and i + 1 < n; ++i) {
        if (a[i - 1] + a[i] > a[i + 1])
            poss = true;
    }

    printf("%spossible\n", poss ? "" : "im");

    return 0;
}
