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

int n;
int a[22];
bool done = false;

void dfs(vector<int>& v1, vector<int>& v2, int x, int y, int p) {
    if (done) return;

    if (x and x == y) {
        for (int x : v1) {
            printf("%d ", x);
        }
        printf("\n");
        for (int x : v2) {
            printf("%d ", x);
        }
        printf("\n");
        done = true;
        return;
    }

    if (p == n) return;

    // go on man
    dfs(v1, v2, x, y, p + 1);

    // try adding to first
    v1.push_back(a[p]);
    x += a[p];
    dfs(v1, v2, x, y, p + 1);
    x -= a[p];
    v1.pop_back();
    
    // try adding to second
    v2.push_back(a[p]);
    y += a[p];
    dfs(v1, v2, x, y, p + 1);
    y -= a[p];
    v2.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + n);

        printf("Case #%d:\n", tc++);
        vector<int> v1, v2;
        done = false;
        dfs(v1, v2, 0, 0, 0);
    }
    
    return 0;
}
