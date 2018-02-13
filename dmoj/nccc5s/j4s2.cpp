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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        int j = i;
        while (j > 1 and a[j - 1] < a[j]) {
            swap(a[j - 1], a[j]);
            --j;
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
