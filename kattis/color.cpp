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

constexpr int MAXN = 100005;
int s, c, k;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &s, &c, &k);
    for (int i = 0; i < s; ++i)
        scanf("%d", a + i);

    sort(a, a + s);
    int i = 0;
    int ans = 0;
    for (; i < s;) {
        int j = i + 1;
        while (j < s and j - i < c and a[j] - a[i] <= k) {
            ++j;
        }

        ++ans;
        i = j;
    }

    printf("%d\n", ans);
    
    return 0;
}
