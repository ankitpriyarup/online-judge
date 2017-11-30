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

    int T;
    scanf("%d", &T);
    int l, n;
    while (T-- > 0) {
        scanf("%d %d", &l, &n);
        vector<int> mins(n, 0);
        vector<int> maxs(n, 0);

        int x;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            mins[i] = min(x, l - x);
            maxs[i] = max(x, l - x);
        }

        printf("%d %d\n", *max_element(begin(mins), end(mins)), *max_element(begin(maxs), end(maxs)));
    }

    return 0;
}
