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

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        int n, k;
        scanf(" %d %d", &n, &k);
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
        }

        sort(begin(a), end(a));
        reverse(begin(a), end(a));
        int score = a[k - 1];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= score)
                ++ans;
            else
                break;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
