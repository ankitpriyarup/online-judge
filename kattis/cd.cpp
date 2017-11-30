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

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 and m == 0) return 0;
        set<int> s;
        int x;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            s.insert(x);
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x);
            if (s.find(x) != end(s))
                ++ans;
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
