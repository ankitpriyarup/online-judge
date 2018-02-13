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

    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n and a[i] <= x; ++i) {
        for (int j = i + 1; j < n and a[j] <= x; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[j] == x)
                    ++ans;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
