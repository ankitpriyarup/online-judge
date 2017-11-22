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

constexpr int MAXN = 30004;
int n;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + n);

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (j < i) j = i;
        while (j < n and a[i] + a[i + 1] > a[j]) {
            ++j;
        }
        ans = max(ans, j - i);
    }

    printf("%d\n", ans);
    
    return 0;
}
