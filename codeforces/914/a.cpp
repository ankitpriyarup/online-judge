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

constexpr int MAXN = 1003;
constexpr int MAXA = 1e6 + 6;
int n;
int a[MAXN];
bool square[MAXA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int x = 0; x * x < MAXA; ++x)
        square[x * x] = true;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + n);
    int p = n - 1;
    while (a[p] >= 0 and square[a[p]]) {
        --p;
    }
    
    printf("%d\n", a[p]);

    return 0;
}
